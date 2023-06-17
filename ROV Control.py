import pygame
import serial
import struct


#Setting
port = 'COM5'
bautRate = 9600

try:
    ser = serial.Serial(port, bautRate, timeout=None)
    arduino = 'ada'
    #startNyelem = 1000
except:
    arduino = 'gada'
    print('------------gada arduino------------')

pygame.init()

#initialise the joystick module
pygame.joystick.init()

#define screen size
SCREEN_WIDTH = 450
SCREEN_HEIGHT = 100

#create game window
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Joysticks")

#define font
font_size = 30
font = pygame.font.SysFont("Futura", font_size)

#function for outputting text onto the screen
def draw_text(text, font, text_col, x, y):
  img = font.render(text, True, text_col)
  screen.blit(img, (x, y))

#create clock for setting game frame rate
clock = pygame.time.Clock()
FPS = 60

#create empty list to store joysticks
joysticks = []

#create player rectangle
x = 225
y = 25
player1 = pygame.Rect(x, y, 50, 50)
x2 = 125
player2 = pygame.Rect(x+x2, y, 50, 50)

xx = 0
yy = 0
xx2 = 0
yy2 = 0

#define player colour
col = "royalblue"

#game loop
run = True
while run:

  clock.tick(FPS)

  #update background
  screen.fill(pygame.Color("midnightblue"))

  #draw player
  player1.topleft = (x, y)
  player2.topleft = (x+x2, y)
  pygame.draw.rect(screen, pygame.Color(col), player1)
  pygame.draw.rect(screen, pygame.Color(col), player2)

  #show number of connected joysticks and text
  draw_text("Controller    : " + str(pygame.joystick.get_count()), font, pygame.Color("azure"), 10, 10)
  draw_text("Temperature: ", font, pygame.Color("azure"), 10, 35)
  draw_text("Leaking        : ", font, pygame.Color("azure"), 10, 60)



  for joystick in joysticks:
    #change player colour with buttons
    if joystick.get_button(0):
      print('turun kecil')
      ser.write('a'.encode('utf-8'))
    if joystick.get_button(1):
      print('yaw kanan kecil')
      ser.write('b'.encode('utf-8'))
    if joystick.get_button(2):
      print('yaw kiri kecil')
      ser.write('c'.encode('utf-8'))
    if joystick.get_button(3):
      print('atas kecil')
      ser.write('d'.encode('utf-8'))

    if joystick.get_button(4):
      print('roll kanan capit')
      ser.write('e'.encode('utf-8'))
    if joystick.get_button(5):
      print('buka capit')
      ser.write('f'.encode('utf-8'))
    if joystick.get_axis(4) > 0:
      print('roll kiri capit')
      ser.write('g'.encode('utf-8'))
    if joystick.get_axis(5) > 0 and joystick.get_axis(5) <= 0.5 :
      print('tutup capit alus')
      ser.write('h'.encode('utf-8'))
    if joystick.get_axis(5) > 0.5:
      print('tutup capit tajem')
      ser.write('i'.encode('utf-8'))

    if joystick.get_button(8):
      print('Analog kiri')
    if joystick.get_button(9):
      print('Analog kanan')



    hats = joystick.get_numhats()
    for i in range(hats):
      hat = joystick.get_hat(i)
      if hat[0]==-1:
        print("kiri kecil")
        x-=5
        ser.write('j'.encode('utf-8'))
      if hat[0]==1:
        print("kanan kecil")
        x+=5
        ser.write('k'.encode('utf-8'))
      if hat[1]==-1:
        print("mundur kecil")
        y+=5
        ser.write('l'.encode('utf-8'))
      if hat[1]==1:
        print("maju kecil")
        y-=5
        ser.write('m'.encode('utf-8'))

    #player movement with left analogue sticks
    horiz_move = joystick.get_axis(0)
    vert_move = joystick.get_axis(1)
    if abs(vert_move) > 0.05:
      y += vert_move * 5
      yy = vert_move * 5
    if abs(horiz_move) > 0.05:
      x += horiz_move * 5
      xx = horiz_move * 5

    #player movement with right analogue sticks
    horiz_move2 = joystick.get_axis(2)
    vert_move2 = joystick.get_axis(3)
    if abs(vert_move2) > 0.05:
      y += vert_move2 * 5
      yy2 = vert_move2 * 5
    if abs(horiz_move2) > 0.05:
      x += horiz_move2 * 5
      xx2 = horiz_move2 * 5

    #Description and transfer code
    if yy >= 2.5:
      print('mundur tajem')
      yy = 0
      ser.write('n'.encode('utf-8'))
    if yy < 2.5 and yy > 1:
      print('mundur halus')
      yy = 0
      ser.write('o'.encode('utf-8'))

    if yy <= -2.5:
      print('maju tajem')
      yy = 0
      ser.write('p'.encode('utf-8'))
    if yy > -2.5 and yy < -1:
      print('maju halus')
      yy = 0
      ser.write('q'.encode('utf-8'))

    if xx >= 2.5:
      print('kanan kepiting tajem')
      xx = 0
      ser.write('r'.encode('utf-8'))
    if xx < 2.5 and xx > 1:
      print('kanan kepiting halus')
      xx = 0
      ser.write('s'.encode('utf-8'))

    if xx <= -2.5:
      print('kiri kepiting tajem')
      xx = 0
      ser.write('t'.encode('utf-8'))
    if xx > -2.5 and xx < -1:
      print('kiri kepiting halus')
      xx = 0
      ser.write('u'.encode('utf-8'))

    if yy2 >= 2.5:
      print('turun tajem')
      yy2 = 0
      ser.write('v'.encode('utf-8'))
    if yy2 < 2.5 and yy2 > 1:
      print('turun halus')
      yy2 = 0
      ser.write('w'.encode('utf-8'))

    if yy2 <= -2.5:
      print('naik tajem')
      yy2 = 0
      ser.write('x'.encode('utf-8'))
    if yy2 > -2.5 and yy2 < -1:
      print('naik halus')
      yy2 = 0
      ser.write('y'.encode('utf-8'))

    if xx2 >= 2.5:
      print('yaw kanan tajem')
      xx2 = 0
      ser.write('z'.encode('utf-8'))
    if xx2 < 2.5 and xx2 > 1:
      print('yaw kanan halus')
      xx2 = 0
      ser.write('A'.encode('utf-8'))

    if xx2 <= -2.5:
      print('yaw kiri tajem')
      xx2 = 0
      ser.write('B'.encode('utf-8'))
    if xx2 > -2.5 and xx2 < -1:
      print('yaw kiri halus')
      xx2 = 0
      ser.write('C'.encode('utf-8'))

  #event handler
  for event in pygame.event.get():
    if event.type == pygame.JOYDEVICEADDED:
      joy = pygame.joystick.Joystick(event.device_index)
      joysticks.append(joy)
    #quit program
    if event.type == pygame.QUIT:
      run = False

  #update display
  pygame.display.flip()

pygame.quit()