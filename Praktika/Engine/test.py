from PyQt5.QtCore import QDate, QTime, QDateTime, Qt
from datetime import datetime

print(datetime.today())
print(type(QDate.currentDate().toString(Qt.ISODate)))