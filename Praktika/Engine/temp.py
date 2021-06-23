import requests
import pandas as pd
import openpyxl
import time
 
def updatefile():
    dls = "https://bdu.fstec.ru/files/documents/vullist.xlsx"
    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.106 Safari/537.36',
        'Referrer': 'https://bdu.fstec.ru/vul%27%7D'}
    resp = requests.get(dls, headers=headers)
 
    output = open('test.xlsx', 'wb')
    output.write(resp.content)
    output.close()
 
 
 
 
def initial_file():
    cols = [4, 7, 8, 9, 12, 14, 15, 16, 21]
    lines = []
    diction = {}
 
    stolbs = pd.read_excel('vullist.xlsx', usecols=cols, skiprows=2)
    counter = -1
    for name in stolbs['Название ПО'].tolist():
        counter += 1
        if "Thunderbird" in str(name):
            print(counter)
            lines.append(counter)
            diction[counter] = "Thunderbird"
    for i in lines:
        programm = stolbs['Название ПО'].tolist()[i]
        os = stolbs['Наименование ОС и тип аппаратной платформы'].tolist()[i]
        class_yazvim = stolbs['Класс уязвимости'].tolist()[i]
        date = stolbs['Дата выявления'].tolist()[i]
        yr_opas = stolbs['Уровень опасности уязвимости'].tolist()[i]
        status_yaz = stolbs['Статус уязвимости'].tolist()[i]
        nal_exploit = stolbs['Наличие эксплойта'].tolist()[i]
        ystr_yaz = stolbs['Информация об устранении'].tolist()[i]
        type_error = stolbs['Тип ошибки CWE'].tolist()[i]
        diction[i] = (programm, os, class_yazvim, date, yr_opas, status_yaz, nal_exploit, ystr_yaz, type_error)
        print(diction[i])
 
initial_file()