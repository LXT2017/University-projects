import time

import jieba
import pandas as pd
import urllib.request
import json
import requests
import base64


#调用百度API的图片识别接口
def get_words(src):
    #获取access_token地址
    host = "https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=6RUONCgT4i7hTfuIvRYi0Cll&client_secret=nl0Dz1nFjaDV6kzPP8xLt56dtjhETDhT"
    page = urllib.request.urlopen(host)
    hjson = json.load(page)
    # print(hjson)
    acces_token = hjson['access_token']

    url = "https://aip.baidubce.com/rest/2.0/ocr/v1/general_basic?access_token=" + acces_token
    with open(src, 'rb') as f:
        image = base64.b64encode(f.read())

    headers = {'Content-Type':'application/x-www-form-urlencoded'}

    data = {'image': image}
    r = requests.post(url, data, headers)
    # print(r.json())
    words_result = r.json()['words_result']
    result = [result['words'] + "\n" for result in words_result]
    doc = "".join(result)
    return doc

#将识别的文字进行jieba分词，并通过去停用词删除不必要的词，进行分词返回
def get_word_from_doc(src):
    stopwords = pd.read_csv("stopwords.txt",
                            index_col=False,
                            quoting=3,
                            sep="\t",
                            names=['stopword'],
                            encoding='utf-8'
                            )
    stopwords = stopwords['stopword'].values
    SUCCESS = False
    count = 1
    #百度API可能会失效
    while not SUCCESS:
        try:
            # time.sleep(1)
            doc = get_words(src)
            SUCCESS = True
        except:
            print("正在进行第%s 次尝试" % count)
            count += 1
            if(count > 10):
                exit(0)
    segs = jieba.lcut(doc)  # jieba分词，存入一个list中
    segs = filter(lambda x: len(x) > 1, segs)  # 只保留长度大于1的词
    segs = filter(lambda x: x not in stopwords, segs)  # 只保留非停用词
    word = " ".join(list(segs))
    return word

#模块单独测试
if __name__ == '__main__':
    print(get_word_from_doc("D:/work/pycharm/workspace/classification/test/test.jpg"))