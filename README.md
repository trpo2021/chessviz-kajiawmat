О проекте:
В данном проекте главной задачей является реализация КРОССПЛАТФОРМЕННОГО (поэтому доска в терминале) приложения, читающего шахматную нотацию в файле res/Chess_Game.txt и отображающего эту шахматную партию на доске. 
В случае ошибки в партии, как записи самого хода, так и в самом ходе, программа оповестит об ошибке, написав в чём ошибка и где она находится.
Программа реализована почти на сложности Nightmare(см. Приложение №1).

Нормальное начало разработки программы 29.04.21 (см. Приложение №2)

Главные постулаты корректности записанных ходов:
1) Запись партии должна быть записана полной нотацией на английском языке. Если одно из этих требований нарушается, то появляется ошибка при чтении партии.
2) Тип фигуры должен быть записан в верхнем регистре, горизонталь -- в нижнем, а вертикаль цифрами.
3) При записи партии допускается писать 'P' при ходе пешки (Например, e2-e4 == Pe2-e4)
4) В случае если пешка дошла последней вертикали, после хода необходимо записать тип фигуры, в которую она превращается. (Кроме самой пешки или короля). В ином случае ошибка.
(забыл о короле при сдаче Лабы №3)
5) Если записан номер хода, то он должен соответсвовать действительности и быть перед ходом белых.
6) Лишние пробелы, точки, комментарии в виде значков опускаются при чтении программы.
7) При взятии фигуры допускается писать и 'x' и ':'.

Запись хода имеет следующий вид:
{Тип_Фигуры}{горизонталь_начала}{вертикаль_начала}{тип_хода}{горизонталь_конца}{вертикаль_конца}

где:
{Тип_Фигуры}={'P','R','N','B','Q','K'};
{горизонталь_начала}=['a';'h'];
{вертикаль_начала}=[1,8];
{тип_хода}={'-','x',':'};
{горизонталь_конца}=['a';'h'];
{вертикаль_конца}=[1,8];

Если записана рокировка, то
{"O-O","O-O-O"} (пробелы между символами допустимы)


Алгоритм программы и немного о реализации:
Первым делом программа должна открыть файл res/Chess_Game.txt для чтения, где записана шахматная партия.
Затем в функции Chess_Game() программа считывает все символы, пока не наткнётся на завершающий символ EOF.

Если символ будет цифрой то вычисляется её значение по цифрово, пока оно не закончится, и проверяется с действительным.

Если указан тип фигуры или горизонталь (то бишь записан ход пешки), программа считывает запись хода, проверяеть по пути его корректность. Затем на логичность 
(взял ли фигуру с указанного поля, какого цвета и подвинулась ли вообще). Если пешка дошла до посл. верт. то записывает и фигуру превращения.
После этого Move_figure() определяет какая фигура ходит, и в зависимости от фигуры проверяется возможность хода (об этом более подробно в отчёте,
который я скину в репозиторий и отправлю вам на проверку вместе с несколькими шахматными партиями.) Если фигура может так походить, то она встаёт 
на это место, а прежнее становится ' ' (Moving()). После этого новая доска рисуется в терминале. Если фигура была срублена, то она пишется; если пешка превратилась,
то пишется в кого и где.

Если указан символ 'O', то программа проверяет сколько раз повторялясь комбинация '-O'. Если кол-во повторений 1 или 2, то всё в порядке. И реализуется принцип рокировки,
допустимость которой проверяется значением в массиве move_rook[], и возможностью пойти фигурам на эти поля. После чего ход отображается и рисуется доска.

В конце партии выводится сообщение "Игра окончена!!!" и на этом программа заканчивается.


----------------
Приложение №1
У рокировки есть 4 условия, при которых она невозможна:
  1) Если Король или рокирующаяся ладья ходила;
  2) Если между королём и ладьёй есть фигура;
! 3) Если Король под шахом;
! 4) Если поля рокировки биты;

Два последних хода не позволяют мне говорить о том, что я сделал приложение на сложности Nightmare, так как в своей программе я реализовал полное игнорирование шаха, мата и пата.
Связано это с тем, что если реализовывать, то это потребуют слишком сравнений и вычислений для определения атак всех фигур. Да и как не реализовать идеальную программу 
с вечной проверкой на шах, мат, пат. Я собирался это реализовать с помощью Attack_Zone[9][9] и Move_Zone[9][9] для всех фигур, но ради этого надо выполнять действий раза в три больше и 
переписывать 800 строчную программу, что мне делать не охота (в рамках приложения для лабораторной, для себя я это сделаю и с графикой для windows (могу потом скинуть скрины)).
Поэтому я не решил реализовывать полностью проверку на рокировку и оставил в таком виде, какой он есть


---------------
Приложение №2 
Приношу свои извенения, что с большинством потока скидываю все свои лабораторные в последнем. На то есть весомое обстоятельство, у которого есть обоснование.
Это не просто какая-то лень, а скорее прокрастинация. Мне страшно делать огромную работу на тему, которую я не знаю, или тем, чем я не обладаю.
Большинство из нас первокурсников, только изучили символьный массив и слегка graphics.h, так что считание файла и разбитие программы на подпрограммы
казалось нам (по крайней мере мне) невероятно трудным. Я до сих пор не понимаю как всю партию реализовать в html, поэтому сделал в консоли по максимуму.
Плюс ко всему изучитили мы эти темы только в апреле, в то время как начали в середине-конце февраля.
И ещё одна причина в том, что из-за трёх предметов по программированию, ты начинаешь не много уставать и у тебя нет желания заниматься огромными проектами.

Но всё же приношу ещё раз свои глубочайшие извенения за то, что отправляю свою работу скорее всего в ночь на 3 мая (сейчас уже 22:27).
Хотя, нет. Я думаю, что как нормальный человек, у которого уже голова болит (дом без дверей с 8-летней сестрой), я сейчас отправлю вам все изменения и пойду спать.
Простите за то, что отправляю работу так поздно. Обещаю не разочаровать вас, нашим курсовым проектом, тестировать и реализовывать алгоритм которой буду я!:)

Пойду спать.