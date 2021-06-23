import sys
from PyQt5 import QtCore, QtGui, QtWidgets, Qt, uic
from PyQt5.QtWidgets import *
import design


Form, _ = uic.loadUiType('design.ui')

def sosi(self):
	print(self.listWidget.currentItem().text())

class main_ui(QMainWindow, Form):
    def __init__(self):
        super(main_ui, self).__init__()
        self.setupUi(self)
        self.initUI()


    def initUI(self):
    	self.listWidget.doubleClicked.connect(lambda : sosi(self))
    	self.btnBrowse.clicked.connect(lambda : sosi(self))


    def close(self):
    	print('sosi')

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    ui1 = main_ui()
    ui1.show()
    sys.exit(app.exec_())