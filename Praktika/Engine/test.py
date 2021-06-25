from PyQt5.QtCore import QDate, QTime, QDateTime, Qt
from datetime import datetime

formatter = '%Y-%m-%d'

date2 = datetime.strptime('2013-03-23', formatter)

date = datetime.strptime(QDate.currentDate().toString(Qt.ISODate), formatter)

print(datetime.today())
print(QDate.currentDate().toString(Qt.ISODate))
print(date)
print('Test ', date > date2)