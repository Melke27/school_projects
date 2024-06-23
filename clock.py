from cs1graphics import*
import time
 
"""
## Student name
1, Fiteh Tesfaye...............ugr/34460/16......49
2, Melkamu Wako................ugr/34915/16......49
3, Nigus Hagos.................ugr/35183/16......49
4, Robassa Adam................ugr/35277/16......50
5, Robel Abebaw................ugr/35278/16......49

This file contains the variable names and some other docmtations.

the variables c1, c2, c3 are variable names for the three circles.
the variables l1, l2, l3 are variable names tor the hands respectivly.
the variables n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12 are variable names for respected numbers.
the variables p1 up to p48 are the variable names for separating points.
variavle text is a variable name for the text we add in the clock.
"""

## this creates the basic structures. 
wall = Canvas(1000,700)
wall.setBackgroundColor("navy")
wall.setTitle("Wall clock.")
#wall.add(back_ground)
wall.setTitle("Clock")
text = Text("Time is life, So don't waste it!")
text.setFontColor("black")
text.setFontSize(10)
text.moveTo(500,450)
frame = Square(600, Point(500, 350))
frame.setBorderWidth(15)
frame.setBorderColor("grey")
frame.setDepth(51)
frame.setFillColor("gold")
wall.add(frame)
## creats the circls and adds them
c1 = Circle(200, Point(500,350))
c2 = Circle(190, Point(500,350))
c3 = Circle(12, Point(500,350))
wall.add(c1)
wall.add(c2)
c3.setFillColor("black")
c3.setBorderColor("black")
c3.setDepth(47)
c1.setFillColor("black")
c2.setFillColor("white")
c2.setBorderWidth(2)
## creats the lines and adds theme
l1 = Path(Point(500,350), Point(500,200))
l1.setBorderColor("black")
l1.setBorderWidth(3)
l1.setDepth(48)
l2 = Path( Point(500,350),Point(500,220))
l2.setBorderColor("black")
l2.setDepth(49)
l2.setBorderWidth(6)
l3 = Path(Point(500,350), Point(590,350))
l3.setBorderColor("black")
l3.setBorderWidth(8.5)
wall.add(l3)
wall.add(l2)
wall.add(l1)
wall.add(text)
wall.add(c3)
## create the numbers and adds theme
n12 = Text('12', 20, Point(498,180))
n12.setFontColor("black")
wall.add(n12)
n3 = Text("3", 20, Point(675,350))
n3.setFontColor("black")
wall.add(n3)
n6 = Text('6', 20, Point(500,520))
n6.setFontColor("black")
wall.add(n6)
n9 = Text("9", 20, Point(325, 350))
n9.setFontColor("black")
wall.add(n9)
n1 = Text("1", 20, Point(585,203))
wall.add(n1)
n1.setFontColor("black")
n2 = Text("2", 20, Point(647,265))
wall.add(n2)
n2.setFontColor("black")
n4 = Text("4", 20, Point(650,437))
n4.setFontColor("black")
wall.add(n4)
n5 = Text("5", 20, Point(585,497))
n5.setFontColor("black")
wall.add(n5)
n7 = Text("7", 20, Point(415,497))
n7.setFontColor("black")
wall.add(n7)
n8 = Text("8", 20, Point(350,435))
n8.setFontColor("black")
wall.add(n8)
n10 = Text("10", 20, Point(353, 265))
n10.setFontColor("black")
wall.add(n10)
n11= Text("11", 20, Point(413, 203))
n11.setFontColor("black")
wall.add(n11)
## points
p1 = Circle(2, Point(517.5,176))
wall.add(p1)
p1.setFillColor("black")
p1.setBorderColor("black")
##
p2 = Circle(2, Point(535,179))
wall.add(p2)
p2.setFillColor("black")
p2.setBorderColor("black")
##
p3 = Circle(2, Point(552.5,183))
wall.add(p3)
p3.setFillColor("black")
p3.setBorderColor("black")
##
p4= Circle(2, Point(570,190))
wall.add(p4)
p4.setFillColor("black")
p4.setBorderColor("black")
##
p5 = Circle(2, Point(602.7, 210))
wall.add(p5)
p5.setFillColor("black")
p5.setBorderColor("black")
##
p6 = Circle(2, Point(617, 220))
wall.add(p6)
p6.setFillColor("black")
p6.setBorderColor("black")
##
p7 = Circle(2, Point(630, 233))
wall.add(p7)
p7.setFillColor("black")
p7.setBorderColor("black")
##
p8 = Circle(2, Point(640, 247.3))
wall.add(p8)
p8.setFillColor("black")
p8.setBorderColor("black")
##
p9 = Circle(2, Point(659.7, 280))
wall.add(p9)
p9.setFillColor("black")
p9.setBorderColor("black")
##
p10 = Circle(2, Point(666.4,297.5))
wall.add(p10)
p10.setFillColor("black")
p10.setBorderColor("black")
##
p11 = Circle(2, Point(671.5, 315))
wall.add(p11)
p11.setFillColor("black")
p11.setBorderColor("black")
##
p12 = Circle(2, Point(674,332.5))
wall.add(p12)
p12.setFillColor("black")
p12.setBorderColor("black")
##
p13 = Circle(2, Point(659.7, 420))
wall.add(p13)
p13.setFillColor("black")
p13.setBorderColor("black")
##
p14 = Circle(2, Point(666.4, 402.5))
wall.add(p14)
p14.setFillColor("black")
p14.setBorderColor("black")
##
p15 = Circle(2, Point(671.5, 385))
wall.add(p15)
p15.setFillColor("black")
p15.setBorderColor("black")
##
p16 = Circle(2, Point(674, 367.5))
wall.add(p16)
p16.setFillColor("black")
p16.setBorderColor("black")
##
p17 = Circle(2, Point(602.7, 490))
wall.add(p17)
p17.setFillColor("black")
p17.setBorderColor("black")
##
p18= Circle(2, Point(617, 480))
wall.add(p18)
p18.setFillColor("black")
p18.setBorderColor("black")
##
p19 = Circle(2, Point(630, 467))
wall.add(p19)
p19.setFillColor("black")
p19.setBorderColor("black")
##
p20= Circle(2, Point(640, 452.7))
wall.add(p20)
p20.setFillColor("black")
p20.setBorderColor("black")
##
p21 = Circle(2, Point(517.5, 524))
wall.add(p21)
p21.setFillColor("black")
p21.setBorderColor("black")
##
p22 = Circle(2, Point(535, 521))
wall.add(p22)
p22.setFillColor("black")
p22.setBorderColor("black")
##
p23 = Circle(2, Point(552.5, 517))
wall.add(p23)
p23.setFillColor("black")
p23.setBorderColor("black")
##
p24 = Circle(2, Point(570, 510))
wall.add(p24)
p24.setFillColor("black")
p24.setBorderColor("black")
##
p25 = Circle(2, Point(430,510))
wall.add(p25)
p25.setFillColor("black")
p25.setBorderColor("black")
##
p26 = Circle(2, Point(447.5,517))
wall.add(p26)
p26.setFillColor("black")
p26.setBorderColor("black")
##
p27 = Circle(2, Point(465,521))
wall.add(p27)
p27.setFillColor("black")
p27.setBorderColor("black")
##
p28 = Circle(2, Point(482.5,524))
wall.add(p28)
p28.setFillColor("black")
p28.setBorderColor("black")
##
p29 = Circle(2, Point(360,452.7))
wall.add(p29)
p29.setFillColor("black")
p29.setBorderColor("black")
##
p30 = Circle(2, Point(370,467))
wall.add(p30)
p30.setFillColor("black")
p30.setBorderColor("black")
##
p31 = Circle(2, Point(383,480))
wall.add(p31)
p31.setFillColor("black")
p31.setBorderColor("black")
##
p32 = Circle(2, Point(397.5,490))
wall.add(p32)
p32.setFillColor("black")
p32.setBorderColor("black")
##
p33 = Circle(2, Point( 326,367.5))
wall.add(p33)
p33.setFillColor("black")
p33.setBorderColor("black")
##
p34= Circle(2, Point(328.5,385))
wall.add(p34)
p34.setFillColor("black")
p34.setBorderColor("black")
##
p35= Circle(2, Point(333.6,402.5 ))
wall.add(p35)
p35.setFillColor("black")
p35.setBorderColor("black")
##
p36= Circle(2, Point(340.3,420))
wall.add(p36)
p36.setFillColor("black")
p36.setBorderColor("black")
##
p37 = Circle(2, Point(326,332.5 ))
wall.add(p37)
p37.setFillColor("black")
p37.setBorderColor("black")
##
p38 = Circle(2, Point(328.5,315))
wall.add(p38)
p38.setFillColor("black")
p38.setBorderColor("black")
##
p39 = Circle(2, Point( 333.6,297.5))
wall.add(p39)
p39.setFillColor("black")
p39.setBorderColor("black")
##
p40 = Circle(2, Point(340.3,280))
wall.add(p40)
p40.setFillColor("black")
p40.setBorderColor("black")
##
p41 = Circle(2, Point(360,247.3 ))
wall.add(p41)
p41.setFillColor("black")
p41.setBorderColor("black")
##
p42 = Circle(2, Point(370,233))
wall.add(p42)
p42.setFillColor("black")
p42.setBorderColor("black")
##
p43 = Circle(2, Point( 383,220))
wall.add(p43)
p43.setFillColor("black")
p43.setBorderColor("black")
##
p44 = Circle(2, Point(397.5,210))
wall.add(p44)
p44.setFillColor("black")
p44.setBorderColor("black")
##
p45 = Circle(2, Point(430,190 ))
wall.add(p45)
p45.setFillColor("black")
p45.setBorderColor("black")
##
p46 = Circle(2, Point(447.5,183))
wall.add(p46)
p46.setFillColor("black")
p46.setBorderColor("black")
##
p47 = Circle(2, Point( 465,179))
wall.add(p47)
p47.setFillColor("black")
p47.setBorderColor("black")
##
p48 = Circle(2, Point(482.5,176))
wall.add(p48)
p48.setFillColor("black")
p48.setBorderColor("black")

## adds the functionality of the time. 
## this while loop ensures that the clock will not stope once it begun counting.
while True:
    ## this for loop runs the second counter.
    for i in range(60):
        l1.rotate(6)
        time.sleep(1)
    ## this code runs the minute counter.
    l2.rotate(6)
    ## this code the hour counter.
    l3.rotate(0.49)