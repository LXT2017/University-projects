

import os

import joblib
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier

import word
os.environ["CUDA_VISIBLE_DEVICES"] = "-1"


#这里用了tf-idf分词以及神经网络内核，可以进行修改
class TextClassifier():
    #100层隐藏层的神经网络
    def __init__(self, classifier=MLPClassifier(hidden_layer_sizes=(100),
                activation='relu',
                solver='adam',
                batch_size=128,
                alpha=1e-4,
                learning_rate_init=1e-3,
                learning_rate='adaptive',
                tol=1e-4,
                max_iter = 200)):
        self.classifier = classifier
        self.vectorizer = TfidfVectorizer(analyzer='word',   # tokenise by character ngrams 解析器：基于空格来区分不同的词
                                          ngram_range=(1,4),  # use ngrams of size 1、2、3 保留单个词，两两词、三三词
                                          max_features=20000)  # keep the most common 20000 ngrams 保留最高频的20000个词

    def features(self, X):
        return self.vectorizer.transform(X)

    def fit(self, X, y):
        self.vectorizer.fit(X)
        self.classifier.fit(self.features(X), y)

    def predict(self, x):
        return self.classifier.predict(self.features([x]))

    def score(self, X, y):
        return self.classifier.score(self.features(X), y)



#os文件操作
def file_name_listdir(file_dir):
    sentences = []
    #从百度API接口获取已经分词过的文字
    for files in os.listdir(file_dir):  # 不仅仅是文件，当前目录下的文件夹也会被认为遍历到
        print("正在识别%s 类图片" % files)
        for file in os.listdir(file_dir + "\\" + files):
            #如果不是.jpg结尾的文件，那么跳过
            if file[-4:] != ".jpg":
                continue
            dir = file_dir + "\\" + files + "\\" + file
            content = word.get_word_from_doc(dir)
            sentences.append((content, files))
    return sentences

#返回模型
def get_data():
    print("开始建立模型...")
    if os.path.exists("model.pkl"):
        print("建立模型中")
        clf = joblib.load("model.pkl")
    # 如果不存在模型，开始训练
    else:
        sentences = file_name_listdir("samples")
        x, y = zip(*sentences)
        x_train, x_test, y_train, y_test = train_test_split(x, y, random_state=1234, test_size=0.20)
        clf = TextClassifier()
        clf.fit(x_train, y_train)
        joblib.dump(clf, "model.pkl",compress=3)
        print("当前模型的准确率为%s" % clf.score(x_test, y_test))
    print("模型训练成功！")
    return clf

#重新训练
def retrain():
    print("正在准备重新训练模型...")
    if os.path.exists("model.pkl"):
        os.remove("model.pkl")
    print("模型删除成功!")
    get_data()

#测试模块
if __name__ == '__main__':
    #samples文件夹里存放训练集
    clf = get_data()
    print(clf.predict("待测图片"))