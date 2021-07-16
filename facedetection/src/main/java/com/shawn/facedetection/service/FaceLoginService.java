package com.shawn.facedetection.service;


import cn.hutool.core.codec.Base64;
import com.shawn.facedetection.util.BaiduAiUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.File;

@Service
public class FaceLoginService {

    // @Value("${qr.url}")
    // private String url;

    @Autowired
    private BaiduAiUtil baiduAiUtil;

    // 判断用户是否注册了面部信息
    public Boolean faceExist(String userId){
        Boolean aBoolean=baiduAiUtil.faceExist(userId);
        return aBoolean;
    }

    /**
     *  人脸注册 ：将用户照片存入人脸库中
     */
    public Boolean faceRegister(String username, String faceBase) {
        Boolean aBoolean = false;
        try {
            baiduAiUtil.faceDelete(username);
            aBoolean = baiduAiUtil.faceRegister(username, faceBase);
        } catch (Exception e) {

        }
        return aBoolean;
    }

    public Boolean faceRegister1(String userId, File file) {
        Boolean aBoolean = false;
        // 人脸注册
        String image= Base64.encode(file);
        try {
            baiduAiUtil.faceDelete(userId);
            aBoolean = baiduAiUtil.faceRegister(userId, image);
        } catch (Exception e) {

        }
        return aBoolean;
    }

    public String loginByFace(String faceBase) throws Exception {
        String userId=baiduAiUtil.faceSearch(faceBase);
        return userId;
    }
}

