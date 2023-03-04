from collections import Counter
from threading import Thread
from PyQt5 import QtCore, QtGui, QtWidgets

from answer_temp import Ui_AnswersWindow
class Ui_TikTokLive(object):
    def openAnswerWindow(self):
        self.window = QtWidgets.QMainWindow()
        self.ui = Ui_AnswersWindow()
        self.ui.setupUi(self.window)
        self.window.show()

    def setupUi(self, TikTokLive):
        TikTokLive.setObjectName("TikTokLive")
        TikTokLive.resize(1111, 841)
        # TikTokLive.setMinimumSize(QtCore.QSize(1111, 841))
        # TikTokLive.setMaximumSize(QtCore.QSize(1100, 16777215))
        TikTokLive.setStyleSheet("background-color: rgb(255, 235, 225);\n"
                                 "")

        self.comments = []
        self.verticalLayout = QtWidgets.QVBoxLayout(TikTokLive)
        self.verticalLayout.setObjectName("verticalLayout")
        self.scrollArea = QtWidgets.QScrollArea(TikTokLive)
        self.scrollArea.setMaximumSize(QtCore.QSize(1980, 16777215))
        self.scrollArea.setWidgetResizable(True)
        self.scrollArea.setObjectName("scrollArea")
        self.scrollArea.setAlignment(QtCore.Qt.AlignCenter)

        self.scrollAreaWidgetContents = QtWidgets.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, -826, 1070, 1622))
        self.scrollAreaWidgetContents.setObjectName("scrollAreaWidgetContents")


        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.scrollAreaWidgetContents)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.frame = QtWidgets.QFrame(self.scrollAreaWidgetContents)
        self.frame.setEnabled(True)
        self.frame.setMinimumSize(QtCore.QSize(1100, 800))
        self.frame.setMaximumSize(QtCore.QSize(1100, 800))
        self.frame.setStyleSheet("background-color: rgb(255, 220, 199);")
        self.frame.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.frame.setFrameShadow(QtWidgets.QFrame.Raised)
        self.frame.setObjectName("frame")

        self.label_8 = QtWidgets.QLabel(self.frame)
        self.label_8.setGeometry(QtCore.QRect(80, 160, 221, 71))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_8.setFont(font)
        self.label_8.setStyleSheet("QLabel{\n"
                                   "    background-color:rgb(40, 229, 250)\n"
                                   "}")
        self.label_8.setScaledContents(False)
        self.label_8.setAlignment(QtCore.Qt.AlignCenter)
        self.label_8.setObjectName("label_8")
        self.label_6 = QtWidgets.QLabel(self.frame)
        self.label_6.setGeometry(QtCore.QRect(630, 640, 331, 71))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_6.setFont(font)
        self.label_6.setStyleSheet("QLabel{\n"
                                   "    background-color:rgb(149, 255, 251)\n"
                                   "}")
        self.label_6.setScaledContents(False)
        self.label_6.setAlignment(QtCore.Qt.AlignCenter)
        self.label_6.setObjectName("label_6")
        self.label_3 = QtWidgets.QLabel(self.frame)
        self.label_3.setGeometry(QtCore.QRect(80, 510, 451, 71))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_3.setFont(font)
        self.label_3.setStyleSheet("QLabel{\n"
                                   "    background-color:rgb(40, 229, 250)\n"
                                   "}")
        self.label_3.setScaledContents(False)
        self.label_3.setAlignment(QtCore.Qt.AlignCenter)
        self.label_3.setObjectName("label_3")
        self.label_5 = QtWidgets.QLabel(self.frame)
        self.label_5.setGeometry(QtCore.QRect(80, 620, 451, 111))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_5.setFont(font)
        self.label_5.setStyleSheet("QLabel{\n"
                                   "    background-color:rgb(40, 229, 250)\n"
                                   "}")
        self.label_5.setScaledContents(False)
        self.label_5.setAlignment(QtCore.Qt.AlignCenter)
        self.label_5.setObjectName("label_5")
        self.lineEdit = QtWidgets.QLineEdit(self.frame)
        self.lineEdit.setGeometry(QtCore.QRect(390, 160, 571, 71))
        font = QtGui.QFont()
        font.setPointSize(14)
        font.setBold(False)
        font.setWeight(50)
        self.lineEdit.setFont(font)
        self.lineEdit.setStyleSheet("background-color: rgb(120, 218, 227);")
        self.lineEdit.setText("")
        self.lineEdit.setAlignment(QtCore.Qt.AlignCenter)
        self.lineEdit.setObjectName("lineEdit")
        self.label_7 = QtWidgets.QLabel(self.frame)
        self.label_7.setGeometry(QtCore.QRect(310, 50, 451, 71))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_7.setFont(font)
        self.label_7.setStyleSheet("QLabel{\n"
                                   "    background-color:rgb(163, 255, 123)\n"
                                   "}")
        self.label_7.setScaledContents(False)
        self.label_7.setAlignment(QtCore.Qt.AlignCenter)
        self.label_7.setObjectName("label_7")
        self.label_2 = QtWidgets.QLabel(self.frame)
        self.label_2.setGeometry(QtCore.QRect(630, 400, 331, 71))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_2.setFont(font)
        self.label_2.setStyleSheet("QLabel{\n"
                                   "    border-color: rgb(0, 85, 255);\n"
                                   "    background-color:rgb(149, 255, 251)\n"
                                   "}")
        self.label_2.setScaledContents(False)
        self.label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.label_2.setObjectName("label_2")
        self.label = QtWidgets.QLabel(self.frame)
        self.label.setGeometry(QtCore.QRect(80, 400, 451, 71))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setStyleSheet("QLabel{\n"
                                 "    background-color:rgb(40, 229, 250)\n"
                                 "}")
        self.label.setScaledContents(False)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.label_4 = QtWidgets.QLabel(self.frame)
        self.label_4.setGeometry(QtCore.QRect(630, 510, 331, 71))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_4.setFont(font)
        self.label_4.setStyleSheet("QLabel{\n"
                                   "    background-color:rgb(149, 255, 251)\n"
                                   "}")
        self.label_4.setScaledContents(False)
        self.label_4.setAlignment(QtCore.Qt.AlignCenter)
        self.label_4.setObjectName("label_4")

        self.pushButton = QtWidgets.QPushButton(self.frame)
        self.pushButton.setGeometry(QtCore.QRect(80, 270, 300, 91))  # 881
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(24)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton.setFont(font)
        self.pushButton.setStyleSheet("QPushButton{\n"
                                      "    background-color:rgb(112, 112, 112);\n"
                                      "    color:rgb(255, 255, 255)\n"
                                      "}")
        self.pushButton.setObjectName("pushButton")
        self.pushButton.clicked.connect(self.startOrStop)

        self.pushButton1 = QtWidgets.QPushButton(self.frame)
        self.pushButton1.setGeometry(QtCore.QRect(460, 270, 500, 91))  # 881
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(24)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton1.setFont(font)
        self.pushButton1.setStyleSheet("QPushButton{\n"
                                       "    background-color:rgb(112, 112, 112);\n"
                                       "    color:rgb(255, 255, 255)\n"
                                       "}")
        self.pushButton1.setObjectName("pushButton1")
        self.pushButton1.clicked.connect(self.extractComments)

        # self.label_9 = QtWidgets.QLabel(self.frame)
        # self.label_9.setGeometry(QtCore.QRect(310, 810, 451, 71))
        # font = QtGui.QFont()
        # font.setFamily("Times New Roman")
        # font.setPointSize(16)
        # font.setBold(True)
        # font.setWeight(75)
        # self.label_9.setFont(font)
        # self.label_9.setStyleSheet("QLabel{\n"
        #                            "    background-color:rgb(163, 255, 123)\n"
        #                            "}")
        # self.label_9.setScaledContents(False)
        # self.label_9.setAlignment(QtCore.Qt.AlignCenter)
        # self.label_9.setObjectName("label_9")
        #
        # self.listWidget = QtWidgets.QListWidget(self.frame)
        # self.listWidget.setGeometry(QtCore.QRect(190, 920, 700, 600))
        # self.listWidget.setMinimumSize(QtCore.QSize(700, 600))
        # self.listWidget.setMaximumSize(QtCore.QSize(1980, 600))
        # font = QtGui.QFont()
        # font.setFamily("Times New Roman")
        # font.setPointSize(14)
        # font.setBold(True)
        # font.setWeight(75)
        # self.listWidget.setFont(font)
        # self.listWidget.setFlow(QtWidgets.QListView.TopToBottom)
        # self.listWidget.setResizeMode(QtWidgets.QListView.Adjust)
        # self.listWidget.setItemAlignment(QtCore.Qt.AlignCenter)
        # self.listWidget.setObjectName("listWidget")
        # self.listWidget.setStyleSheet("""
        #     QListWidget {
        #         padding:10px;
        #         background-color:#faddbb;
        #
        #     }
        #     QListWidget::item {
        #         margin:10px;
        #
        #     }
        # """)

        self.verticalLayout_2.addWidget(self.frame)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.verticalLayout.addWidget(self.scrollArea)

        self.retranslateUi(TikTokLive)
        QtCore.QMetaObject.connectSlotsByName(TikTokLive)

    def startOrStop(self):
        _translate = QtCore.QCoreApplication.translate
        if self.pushButton.text() == "Connect":
            self.pushButton.setText(_translate("TikTokLive", "Stop"))
            self.commentThread = Thread(target=connectStream, args=(self.lineEdit.text().strip(), 0,))
            self.commentThread.start()
            # commentThread.join()

        else:
            self.pushButton.setText(_translate("TikTokLive", "Start"))
            connectStream("", 1)
            self.commentThread.join()

    def extractComments(self):
        _translate = QtCore.QCoreApplication.translate

        global extract_comments

        if self.pushButton1.text() == "Extract Comments":
            print("Extracting comments")
            self.pushButton1.setText(_translate("TikTokLive", "Stop Extracting"))
            extract_comments = True
            self.openAnswerWindow()

            # commentThread.join()

        else:
            print("Stop extracting comments")
            self.pushButton1.setText(_translate("TikTokLive", "Extract Comments"))
            extract_comments = False

            answers = []
            for element in self.comments:
                answers.append(element[0])

            frequent_answer = self.most_frequent(answers)
            _translate = QtCore.QCoreApplication.translate
            self.label_2.setText(_translate("TikTokLive", frequent_answer))


    def most_frequent(self, List):
        occurence_count = Counter(List)
        return occurence_count.most_common(1)[0][0]

    def addComment(self, comment, username, TikTokLive):
        if "answer" in comment.lower():
            comment = comment.split("answer")[1].strip()
            self.comments.append([comment, username])
            print(comment + " By " + str(username))

            item = QtWidgets.QListWidgetItem()
            item.setText(comment + " By " + str(username))
            item.setTextAlignment(QtCore.Qt.AlignHCenter)

            self.ui.listWidget_2.addItem(item)
            # self.listWidget.addItem(item)

    # def updateCommentSection(self):
    #     for comment in self.comments:
    #         item = QtWidgets.QListWidgetItem()
    #         item.setText(comment)
    #         item.setTextAlignment(QtCore.Qt.AlignHCenter)
    #
    #         self.listWidget.addItem(item)

    def retranslateUi(self, TikTokLive):
        _translate = QtCore.QCoreApplication.translate
        TikTokLive.setWindowTitle(_translate("TikTokLive", "Quiz Control Panel"))
        self.label_8.setText(_translate("TikTokLive", "USER ID"))
        self.label_6.setText(_translate("TikTokLive", "Answer"))
        self.label_3.setText(_translate("TikTokLive", "Correct Answer"))
        self.label_5.setText(_translate("TikTokLive", "Quicket Player To \n"
                                                      "Answer Correctly"))
        self.label_7.setText(_translate("TikTokLive", "QUIZ CONTROL PANEL"))
        self.label_2.setText(_translate("TikTokLive", ""))
        self.label.setText(_translate("TikTokLive", "Most Popular Answer"))
        self.label_4.setText(_translate("TikTokLive", "Answer"))
        self.pushButton.setText(_translate("TikTokLive", "Connect"))
        self.pushButton1.setText(_translate("TikTokLive", "Extract Comments"))

        # self.label_9.setText(_translate("TikTokLive", "QUIZ ANSWERS"))
        # __sortingEnabled = self.listWidget.isSortingEnabled()
        # self.listWidget.setSortingEnabled(False)
        # item = self.listWidget.item(0)
        # item.setText(_translate("TikTokLive", "Comment 1 By User 1"))

        # for comment in self.comments:
        #     item = QtWidgets.QListWidgetItem()
        #     item.setText(comment)
        #     item.setTextAlignment(QtCore.Qt.AlignHCenter)
        #
        #     self.listWidget.addItem(item)

        # self.listWidget.setSortingEnabled(__sortingEnabled)


# TikTok Part

from TikTokLive import TikTokLiveClient
from TikTokLive.types.events import CommentEvent, ConnectEvent, GiftEvent, ShareEvent, LikeEvent, FollowEvent

clients = []
extract_comments = False


def connectStream(video_id, status):
    global clients
    if status == 0:
        print(f"Video id : {video_id}")
        client: TikTokLiveClient = TikTokLiveClient(
            unique_id=video_id, **(
                {
                    "enable_extended_gift_info": True,
                }
            )
        )
        clients.append(client)

        @client.on("connect")
        async def on_connect(event: ConnectEvent):
            print("Connected to the livestream!")

        @client.on("comment")
        async def on_connect(event: CommentEvent):
            # comments.append([event.user.userId, event.comment])
            if extract_comments:
                ui.addComment(event.comment, event.user.nickname, tiktok_live)
                # print(f"{event.user.nickname} commented on the video saying {event.comment}\n")

        # @client.on("gift")
        # async def on_gift(event: GiftEvent):
        #     print(f"{event.user.nickname} sent a {event.gift.giftId}\n")
        #
        # @client.on("follow")
        # async def on_follow(event: FollowEvent):
        #     print(f"{event.user.nickname} has started following you.\n")
        #
        # @client.on("like")
        # async def on_like(event: LikeEvent):
        #     print(f"{event.user.nickname} liked the video\n")
        #
        # @client.on("share")
        # async def on_share(event: ShareEvent):
        #     print(f"{event.user.nickname} shared the video\n")

        client.run()

    else:
        if clients[0] != None:
            print("Disconnecting!")
            clients[0].stop()

            clients = []
            raise Exception()


app = None
tiktok_live = None
if __name__ == "__main__":
    try:
        import sys

        app = QtWidgets.QApplication(sys.argv)
        tiktok_live = QtWidgets.QWidget()
        ui = Ui_TikTokLive()
        ui.setupUi(tiktok_live)
        tiktok_live.show()
        sys.exit(app.exec_())

    except:
        print("Error Occurred")
