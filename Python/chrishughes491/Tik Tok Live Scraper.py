from collections import Counter
from threading import Thread
from PyQt5 import QtCore, QtGui, QtWidgets
from answer_window import Ui_AnswersWindow


class Ui_MainWindow(object):
    def openAnswerWindow(self):
        self.window = QtWidgets.QMainWindow()
        self.ui = Ui_AnswersWindow()
        self.ui.setupUi(self.window)
        self.window.show()

    def setupUi(self, MainWindow):
        self.comments = []

        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1074, 752)
        MainWindow.setStyleSheet("background-color: rgb(255, 235, 225);\n"
                                 "")
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName("verticalLayout")
        self.scrollArea = QtWidgets.QScrollArea(self.centralwidget)
        self.scrollArea.setStyleSheet("background-color: rgb(255, 220, 199);")
        self.scrollArea.setWidgetResizable(True)
        self.scrollArea.setObjectName("scrollArea")
        self.scrollAreaWidgetContents = QtWidgets.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 1050, 703))
        self.scrollAreaWidgetContents.setObjectName("scrollAreaWidgetContents")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.scrollAreaWidgetContents)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.frame = QtWidgets.QFrame(self.scrollAreaWidgetContents)
        self.frame.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.frame.setFrameShadow(QtWidgets.QFrame.Raised)
        self.frame.setObjectName("frame")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.frame)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setContentsMargins(200, -1, 200, -1)
        self.gridLayout.setObjectName("gridLayout")
        self.label_7 = QtWidgets.QLabel(self.frame)
        self.label_7.setEnabled(True)
        self.label_7.setMinimumSize(QtCore.QSize(400, 75))
        self.label_7.setMaximumSize(QtCore.QSize(16777215, 100))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_7.setFont(font)
        self.label_7.setStyleSheet("QLabel{\n"
                                   "    background-color:rgb(163, 255, 123);\n"
                                   "\n"
                                   "}")
        self.label_7.setScaledContents(False)
        self.label_7.setAlignment(QtCore.Qt.AlignCenter)
        self.label_7.setObjectName("label_7")
        self.gridLayout.addWidget(self.label_7, 0, 0, 1, 1)
        self.verticalLayout_3.addLayout(self.gridLayout)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.userid_label = QtWidgets.QLabel(self.frame)
        self.userid_label.setMinimumSize(QtCore.QSize(250, 75))
        self.userid_label.setMaximumSize(QtCore.QSize(600, 75))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.userid_label.setFont(font)
        self.userid_label.setStyleSheet("QLabel{\n"
                                        "    background-color:rgb(40, 229, 250);\n"
                                        "    \n"
                                        "}")
        self.userid_label.setScaledContents(False)
        self.userid_label.setAlignment(QtCore.Qt.AlignCenter)
        self.userid_label.setObjectName("userid_label")
        self.horizontalLayout.addWidget(self.userid_label)
        self.lineEdit = QtWidgets.QLineEdit(self.frame)
        self.lineEdit.setMinimumSize(QtCore.QSize(400, 100))
        self.lineEdit.setMaximumSize(QtCore.QSize(600, 100))
        font = QtGui.QFont()
        font.setPointSize(14)
        font.setBold(False)
        font.setWeight(50)
        self.lineEdit.setFont(font)
        self.lineEdit.setStyleSheet("background-color: rgb(120, 218, 227);\n"
                                    "margin: 10px 0px\n"
                                    "")
        self.lineEdit.setText("")
        self.lineEdit.setAlignment(QtCore.Qt.AlignCenter)
        self.lineEdit.setObjectName("lineEdit")
        self.horizontalLayout.addWidget(self.lineEdit)
        self.horizontalLayout.setStretch(0, 1)
        self.horizontalLayout.setStretch(1, 2)
        self.verticalLayout_3.addLayout(self.horizontalLayout)
        self.horizontalLayout_6 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_6.setObjectName("horizontalLayout_6")
        self.pushButton_2 = QtWidgets.QPushButton(self.frame)
        self.pushButton_2.setMaximumSize(QtCore.QSize(600, 100))
        self.pushButton_2.clicked.connect(self.startOrStop)


        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(24)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_2.setFont(font)
        self.pushButton_2.setStyleSheet("background-color:rgb(112, 112, 112);\n"
                                        "color:rgb(255, 255, 255);\n"
                                        "padding: 20px 0px")
        self.pushButton_2.setObjectName("pushButton_2")
        self.horizontalLayout_6.addWidget(self.pushButton_2)
        self.pushButton = QtWidgets.QPushButton(self.frame)
        self.pushButton.setMaximumSize(QtCore.QSize(600, 100))
        self.pushButton.clicked.connect(self.extractComments)

        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(24)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton.setFont(font)
        self.pushButton.setStyleSheet("QPushButton{\n"
                                      "    background-color:rgb(112, 112, 112);\n"
                                      "    color:rgb(255, 255, 255);\n"
                                      "    padding: 20px 0px\n"
                                      "\n"
                                      "\n"
                                      "}")
        self.pushButton.setObjectName("pushButton")
        self.horizontalLayout_6.addWidget(self.pushButton)
        self.horizontalLayout_6.setStretch(0, 3)
        self.horizontalLayout_6.setStretch(1, 4)
        self.verticalLayout_3.addLayout(self.horizontalLayout_6)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label = QtWidgets.QLabel(self.frame)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label.sizePolicy().hasHeightForWidth())
        self.label.setSizePolicy(sizePolicy)
        self.label.setMinimumSize(QtCore.QSize(400, 75))
        self.label.setMaximumSize(QtCore.QSize(600, 100))
        self.label.setBaseSize(QtCore.QSize(200, 100))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setStyleSheet("QLabel{\n"
                                 "    background-color:rgb(40, 229, 250);\n"
                                 "}")
        self.label.setScaledContents(False)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.horizontalLayout_2.addWidget(self.label)
        self.label_2 = QtWidgets.QLabel(self.frame)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Ignored, QtWidgets.QSizePolicy.Ignored)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_2.sizePolicy().hasHeightForWidth())
        self.label_2.setSizePolicy(sizePolicy)
        self.label_2.setMinimumSize(QtCore.QSize(300, 100))
        self.label_2.setMaximumSize(QtCore.QSize(600, 100))
        self.label_2.setBaseSize(QtCore.QSize(100, 100))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_2.setFont(font)
        self.label_2.setStyleSheet("QLabel{\n"
                                   "    background-color:rgb(149, 255, 251);\n"
                                   "\n"
                                   "}")
        self.label_2.setScaledContents(False)
        self.label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.label_2.setObjectName("label_2")
        self.horizontalLayout_2.addWidget(self.label_2)
        self.horizontalLayout_2.setStretch(0, 2)
        self.horizontalLayout_2.setStretch(1, 1)
        self.verticalLayout_3.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_3 = QtWidgets.QLabel(self.frame)
        self.label_3.setMinimumSize(QtCore.QSize(400, 75))
        self.label_3.setMaximumSize(QtCore.QSize(600, 100))
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
        self.horizontalLayout_3.addWidget(self.label_3)
        self.label_4 = QtWidgets.QLabel(self.frame)
        self.label_4.setMinimumSize(QtCore.QSize(300, 75))
        self.label_4.setMaximumSize(QtCore.QSize(600, 100))
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
        self.horizontalLayout_3.addWidget(self.label_4)
        self.horizontalLayout_3.setStretch(0, 2)
        self.horizontalLayout_3.setStretch(1, 1)
        self.verticalLayout_3.addLayout(self.horizontalLayout_3)
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.label_5 = QtWidgets.QLabel(self.frame)
        self.label_5.setMinimumSize(QtCore.QSize(400, 75))
        self.label_5.setMaximumSize(QtCore.QSize(600, 100))
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
        self.horizontalLayout_4.addWidget(self.label_5)
        self.label_6 = QtWidgets.QLabel(self.frame)
        self.label_6.setMinimumSize(QtCore.QSize(300, 75))
        self.label_6.setMaximumSize(QtCore.QSize(600, 100))
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
        self.horizontalLayout_4.addWidget(self.label_6)
        self.horizontalLayout_4.setStretch(0, 2)
        self.horizontalLayout_4.setStretch(1, 1)
        self.verticalLayout_3.addLayout(self.horizontalLayout_4)
        self.verticalLayout_2.addWidget(self.frame)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.verticalLayout.addWidget(self.scrollArea)
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def startOrStop(self):
        _translate = QtCore.QCoreApplication.translate
        if self.pushButton_2.text() == "Connect":
            self.pushButton_2.setText(_translate("TikTokLive", "Stop"))
            self.commentThread = Thread(target=connectStream, args=(self.lineEdit.text().strip(), 0,))
            self.commentThread.start()
            # commentThread.join()

        else:
            self.pushButton_2.setText(_translate("TikTokLive", "Start"))
            connectStream("", 1)
            self.commentThread.join()

    def extractComments(self):
        _translate = QtCore.QCoreApplication.translate

        global extract_comments

        if self.pushButton.text() == "Extract Comments":
            print("Extracting comments")
            self.pushButton.setText(_translate("TikTokLive", "Stop Extracting"))
            extract_comments = True
            self.openAnswerWindow()

            # commentThread.join()

        else:
            print("Stop extracting comments")
            self.pushButton.setText(_translate("TikTokLive", "Extract Comments"))
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

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label_7.setText(_translate("MainWindow", "QUIZ CONTROL PANEL"))
        self.userid_label.setText(_translate("MainWindow", "USER ID"))
        self.pushButton_2.setText(_translate("MainWindow", "Connect"))
        self.pushButton.setText(_translate("MainWindow", "Extract Comments"))
        self.label.setText(_translate("MainWindow", "Most Popular Answer"))
        self.label_2.setText(_translate("MainWindow", "Answer"))
        self.label_3.setText(_translate("MainWindow", "Correct Answer"))
        self.label_4.setText(_translate("MainWindow", "Answer"))
        self.label_5.setText(_translate("MainWindow", "Quicket Player To \n"
                                                      "Answer Correctly"))
        self.label_6.setText(_translate("MainWindow", "Answer"))


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
        MainWindow = QtWidgets.QMainWindow()
        ui = Ui_MainWindow()
        ui.setupUi(MainWindow)
        MainWindow.show()
        sys.exit(app.exec_())

    except:
        print("Error Occurred")
