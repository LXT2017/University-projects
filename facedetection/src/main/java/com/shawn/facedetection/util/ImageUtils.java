package com.shawn.facedetection.util;

import javax.servlet.http.HttpServletRequest;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.util.Base64;
import java.util.Base64.Decoder;
import java.util.UUID;

/**
 * 图像跑龙套
 *
 * @author Shawn
 * @date 2021/07/16
 */
public class ImageUtils {

    /**
     * 上传图片到指定位置
     * @param request
     * @param picName 客户端文件的name
     * @param picPath 文件上传的路径
     * @return
     */
    public static File uploadImg(HttpServletRequest request, String picName, String picPath) {
        //获取客户端传输到服务器的图片
        String imgData = request.getParameter(picName);
        //获取指定的图片上传到服务器的路径
        String path = System.getProperty("user.dir") + "/"+picPath+"/";
        //给图片一个随机名称
        String fileName = UUID.randomUUID().toString().replace("-", "")+".png";
        boolean flag;
        if (imgData != null) {
            //上传图片
            flag = generateImage(imgData.substring(22), path, fileName);
        }
        System.out.println("图片上传:,地址："+path);
        return new File(path+"/"+fileName);
    }

    private static boolean generateImage(String imgStr, String filePath, String fileName) {
        try {
            if (imgStr == null) {
                return false;
            }
            Decoder decoder = Base64.getDecoder();
            byte[] b = decoder.decode(imgStr);
            File file = new File(filePath);
            if (!file.exists()) {
                file.mkdirs();
            }
            OutputStream out = new FileOutputStream(filePath+fileName);
            out.write(b);
            out.flush();
            out.close();
            return true;
        } catch (Exception e) {
            return false;
        }
    }

}

