package com.shawn.facedetection.controller;


import com.shawn.facedetection.service.FaceLoginService;
import com.shawn.facedetection.util.BaiduAiUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

@RestController
@RequestMapping("/face")
@CrossOrigin
public class FaceLoginController {


    @Autowired
    private FaceLoginService faceLoginService;

    @Resource
    private BaiduAiUtil baiduAiUtil;

    @RequestMapping("/")
    public String hello() {
        return "login";
    }

    /**
     * 人脸登录：根据落地页随机拍摄的面部头像进行登录
     *          根据拍摄的图片调用百度云AI进行检索查找
     */
    @RequestMapping("/login")
    @ResponseBody
    public String face(String username,String faceBase)  throws Exception{
        String userId= faceLoginService.loginByFace(faceBase);
        if (username.equals(userId)){
            return "1";
        }
        return "2";
    }

    @RequestMapping("/register")
    @ResponseBody
    public String register(String username,String faceBase) throws Exception {
        System.out.println("注册");
        // File file = ImageUtils.uploadImg(request, "imgData", "upimg");
        faceLoginService.faceRegister(username, faceBase);
        return "1";
    }

}

