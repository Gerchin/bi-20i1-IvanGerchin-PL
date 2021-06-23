from openpyxl import load_workbook
from datetime import datetime
from data import *
from matplotlib.pyplot import *

workbook = load_workbook('vullist.xlsx')
sheet = workbook.active




#print(datetime.strptime(td, formatter))

piles = [2, 3, 5, 7, 9, 10, 13, 15, 16, 17, 21]

counter = 0

colum = {
	'2': 'Наименование уязвимости',
	'3': 'Описание уязвимости',
	'5': 'Название ПО',
	'7': 'Тип ПО',
	'9': 'Класс уязвимости',
	'10': 'Дата выявления',
	'13': 'Уровень опасности уязвимости',
	'15': 'Статус уязвимости',
	'16': 'Наличие эксплойта',
	'17': 'Информация об устранении',
	'21': 'Описание ошибки CWE'}

for row in range(1, sheet.max_row):
	if 'Microsoft Edge' in str(sheet.cell(row=row, column=5).value):
		nameU.append(sheet.cell(row=row, column=2).value)
		discription.append(sheet.cell(row=row, column=3).value)
		soft.append(sheet.cell(row=row, column=5).value)
		softType.append(sheet.cell(row=row, column=7).value)
		classU.append(sheet.cell(row=row, column=9).value)
		dateOfFind.append(sheet.cell(row=row, column=10).value)
		dangerLevel.append(sheet.cell(row=row, column=13).value)
		status.append(sheet.cell(row=row, column=15).value)
		explExists.append(sheet.cell(row=row, column=16).value)
		info.append(sheet.cell(row=row, column=17).value)
		cwe.append(sheet.cell(row=row, column=21).value)
		#print(soft[counter], nameU[counter], dateOfFind[counter])
		counter +=1

def countCheck(listToCount):
	ct = 0
	for t in listToCount:
		ct += 1
	return ct

print(countCheck(nameU))
print(countCheck(soft))

def date_perform(date):
	formatter = "%d.%m.%Y"
	dateP = datetime.strptime(date, formatter)
	return dateP

def sort(date_until, date_after, dangerLevel=0, status=False, explExists=False):
	counter = 0
	for i in nameU.length():
		if date_perform(dateOfFind[i]) < date_perform(date_after) & date_perform(dateOfFind[i]) > date_perform(date_until):
			counter += 1

	sorted_data = [[0]*11 for i in range(counter)]

	print(sorted_data)

#sort('12.03.2016', '21.05.2021')

#plot(nameU)
#show()