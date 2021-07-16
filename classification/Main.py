# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Main.ui'
#
# Created by: PyQt5 UI code generator 5.13.0
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets
import shutil
from PyQt5.QtCore import QThread
from PyQt5.QtWidgets import *
import classifier
import os
import word


class Ui_Form(object):

    def openfile(self):
        fileName, filetype = QFileDialog.getOpenFileName(self.layoutWidget,
                                                          "选取文件",
                                                          "classification",
                                                          "Pic Files (*.jpg)")  # 设置文件扩展名过滤,注意用双分号间隔
        self.label_2.setText(fileName)
        self.textBrowser.clear()

    #进行分类
    def classify(self):
        if  self.flag == 1 and self.thread.isRunning():
            QMessageBox.warning(self.layoutWidget, '警告', '当前模型正在重新训练，请训练完成后在进行归类操作！', QMessageBox.Yes)
            self.label_2.clear()
            return
        print(2222)
        if(self.label_2.text() == ""):
            # 警告对话框
            QMessageBox.warning(self.layoutWidget, '警告', '请先选择要分类的图片', QMessageBox.Yes)
            return
        clf = classifier.get_data()
        print(self.label_2.text())
        text = word.get_word_from_doc(self.label_2.text())
        result = clf.predict(text)
        self.result = "".join(result)
        result = "图片预测结果类别为 " + "".join(result) + "\n已成功归类"
        self.textBrowser.setText(result)
        self.movefile()
        self.label_2.clear()

    # 归类所有待测文件
    def classifyAll(self):
        if self.flag == 1 and self.thread.isRunning():
            QMessageBox.warning(self.layoutWidget, '警告', '当前模型正在重新训练，请训练完成后在进行归类操作！', QMessageBox.Yes)
            self.label_2.clear()
            return
        self.textBrowser.setText("分类中，请稍后...")
        clf = classifier.get_data()
        for file in os.listdir("test"):  # 不仅仅是文件，当前目录下的文件夹也会被认为遍历到
            print("分类%s 图片成功" % file)
            # 如果不是.jpg结尾的文件，那么跳过
            if file[-4:] != ".jpg":
                continue
            text = word.get_word_from_doc("test//" + file)
            result = "".join(clf.predict(text))
            shutil.move("test//" + file,"samples//" + result)
        self.textBrowser.setText("分类完成！")



    #移动文件到响应地方
    def movefile(self):
        print(self.result)
        shutil.move(self.label_2.text(),"samples//" + self.result)

    #重新训练
    def retrain(self):
        word = "正在重新训练模型，请稍等片刻..."
        self.textBrowser.setText(word)
        self.thread = Thread()
        self.thread.start()
        #self.textBrowser.setText("模型训练成功！")

    def setupUi(self, Form):
        self.flag = 0
        Form.setObjectName("Form")
        Form.resize(400, 291)
        self.label_2 = QtWidgets.QLabel(Form)
        self.label_2.setGeometry(QtCore.QRect(50, 80, 291, 20))
        font = QtGui.QFont()
        font.setFamily("Adobe Devanagari")
        font.setPointSize(10)
        self.label_2.setFont(font)
        self.label_2.setText("")
        self.label_2.setObjectName("label_2")
        self.layoutWidget = QtWidgets.QWidget(Form)
        self.layoutWidget.setGeometry(QtCore.QRect(51, 41, 291, 29))
        self.layoutWidget.setObjectName("layoutWidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label = QtWidgets.QLabel(self.layoutWidget)
        font = QtGui.QFont()
        font.setFamily("Adobe Devanagari")
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.horizontalLayout.addWidget(self.label)
        self.toolButton = QtWidgets.QToolButton(self.layoutWidget)
        self.toolButton.setObjectName("toolButton")
        self.horizontalLayout.addWidget(self.toolButton)

        # 添加事件
        self.toolButton.clicked.connect(self.openfile)

        self.layoutWidget1 = QtWidgets.QWidget(Form)
        self.layoutWidget1.setGeometry(QtCore.QRect(50, 110, 291, 161))
        self.layoutWidget1.setObjectName("layoutWidget1")
        self.gridLayout = QtWidgets.QGridLayout(self.layoutWidget1)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")
        self.pushButton_2 = QtWidgets.QPushButton(self.layoutWidget1)
        self.pushButton_2.setObjectName("pushButton_2")
        self.gridLayout.addWidget(self.pushButton_2, 0, 0, 1, 1)

        # 添加事件
        self.pushButton_2.clicked.connect(self.classify)

        self.pushButton = QtWidgets.QPushButton(self.layoutWidget1)
        self.pushButton.setObjectName("pushButton")
        self.gridLayout.addWidget(self.pushButton, 0, 1, 1, 1)

        # 添加事件
        self.pushButton.clicked.connect(self.retrain)

        self.textBrowser = QtWidgets.QTextBrowser(self.layoutWidget1)
        self.textBrowser.setObjectName("textBrowser")
        self.gridLayout.addWidget(self.textBrowser, 2, 0, 1, 2)
        self.pushButton_3 = QtWidgets.QPushButton(self.layoutWidget1)
        self.pushButton_3.setObjectName("pushButton_3")
        self.gridLayout.addWidget(self.pushButton_3, 1, 0, 1, 2)

        # 添加事件
        self.pushButton_3.clicked.connect(self.classifyAll)

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "图片分类器"))
        self.label.setText(_translate("Form", "请选择要分类的图片"))
        self.toolButton.setText(_translate("Form", "..."))
        self.pushButton_2.setText(_translate("Form", "分类"))
        self.pushButton.setText(_translate("Form", "重新训练模型"))
        self.pushButton_3.setText(_translate("Form", "一键自动分类"))


class Thread(QThread):

    def __init__(self):
        super().__init__()

    def run(self):
        # 线程相关代码
        self.flag = 1
        classifier.retrain()
        QMessageBox.warning(self.layoutWidget, '提示', '模型训练成功！', QMessageBox.Yes)
        self.flag = 0
        pass

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_Form()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())