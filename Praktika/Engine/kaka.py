from tkinter import *

window = Tk()
window.title('Анализ уязвимостей')
w = window.winfo_screenwidth()
h = window.winfo_screenheight()
window.geometry('{}x{}'.format(w//2, h//2))
window.resizable(False, False)

def Popa(event):
	print('popa')

dglbl = Label(window, text='Уровень угрозы')
var = IntVar()
#dg0 = Radiobutton(variable=var, text='Ничего', value=0)
dg1 = Radiobutton(variable=var, text='Низкий уровень угорзы', value=1)
dg2 = Radiobutton(variable=var, text='Средний уровень угрозы', value=2)
dg3 = Radiobutton(variable=var, text='Высокий уровень угрозы', value=3)
dg4 = Radiobutton(variable=var, text='Критический уровень угрозы', value=4)

chk = BooleanVar()
chk.set(False)
diag = Checkbutton(window, text='Нарисовать диаграмму', var=chk)

emtylabel = Label(window, text=' ')
statuslbl = Label(window, text='Статус уязвимости')
var2 = IntVar()
statusrd1 = Radiobutton(variable=var2, text='Подтверждена производителем', value=1)
statusrd2 = Radiobutton(variable=var2, text='Потенциальная уязвимость', value=2)

expllbl = Label(window, text='Наличие эксплойта')
var3 = IntVar()
expl1 = Radiobutton(variable=var3, text='Существует', value=1)
expl2 = Radiobutton(variable=var3, text='Данные уточняются', value=2)

btn = Button(window, text='Сделать отчёт', width=20, height=2, bg='white', fg='black')
btn.bind('<Button-1>', Popa)

dglbl.pack(anchor='w')
#dg0.pack()
dg1.pack(anchor='w')
dg2.pack(anchor='w')
dg3.pack(anchor='w')
dg4.pack(anchor='w')
emtylabel.pack()
statuslbl.pack(anchor='w', side='top')
statusrd1.pack(anchor='w')
statusrd2.pack(anchor='w')
btn.pack(side='bottom')
diag.pack(side='bottom')

window.mainloop()