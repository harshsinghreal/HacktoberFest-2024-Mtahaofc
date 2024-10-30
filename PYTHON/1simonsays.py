import pygame
from random import randint
from time import sleep
pygame.init()
(w, h) = (450, 450)
scr = pygame.display.set_mode((w, h))
pygame.display.set_caption('SIMON SAYS')
pygame.display.flip()
red = [255, 0, 0]
green = [0, 255, 0]
blue = [0, 0, 255]
yellow = [255, 255, 0]
class Button:
    def __init__(self, color, pos):
        self.color = color
        self.pos =  pos
        self.shape = pygame.Rect
        self.draw()
    def draw(self):
        self.shape = pygame.draw.rect(scr, self.color, self.pos)
    def darken(self):
        index = 0
        for i in self.color:
            if i == 255:
                i -= 95
                self.color[index] = i
            index += 1
        self.draw()
        pygame.display.update()
    def lighten(self):
        index = 0
        for i in self.color:
            if i == 160:
                i += 95
                self.color[index] = i
            index += 1
        self.draw()
        pygame.display.update()
    def dark_then_light(self):
        self.darken()
        beep()
        sleep(.5)
        self.lighten()
red_square = Button(red, (25, 25, 200, 200))
green_square = Button(green, (225, 25, 200, 200))
blue_square = Button(blue, (25, 225, 200, 200))
yellow_square = Button(yellow, (225, 225, 200, 200))
pygame.display.update()
beep_sound = pygame.mixer.Sound(r"PYTHON/1beep.wav")
intro_sound = pygame.mixer.Sound(r"PYTHON/1intro.wav")
def intro():
    intro_sound.play()
def beep():
    beep_sound.play()
def click():
    global player_list
    pos = pygame.mouse.get_pos()
    if (25 < pos[0] < 225) and (25 < pos[1] < 225):
        press(0)
        player_list.append(0)
    elif (225 < pos[0] < 425) and (25 < pos[1] < 225):
        press(1)
        player_list.append(1)
    elif (25 < pos[0] < 225) and (225 < pos[1] < 425):
        press(2)
        player_list.append(2)
    elif (225 < pos[0] < 425) and (225 < pos[1] < 425):
        press(3)
        player_list.append(3)
def press(index):
    if index == 0:
        red_square.dark_then_light()
    elif index == 1:
        green_square.dark_then_light()
    elif index == 2:
        blue_square.dark_then_light()
    elif index == 3:
        yellow_square.dark_then_light()
font_name = pygame.font.match_font('Bauhaus 93 Regular')
def draw_text(surf, text, size, x, y):
    font = pygame.font.Font(font_name, size)
    text_surface = font.render(text, True, (255, 255, 255))
    text_rect = text_surface.get_rect()
    text_rect.midtop = (x, y)
    surf.blit(text_surface, text_rect)
def erase_text():
    pygame.draw.rect(scr, (0, 0, 0), (0, 0, 450, 25))
correct_list = []
player_list = []
def ai_turn():
    global AI_turn, player_turn, correct_list
    index = randint(0, 3)
    correct_list.append(index)
    for i in correct_list:
        press(i)
        sleep(.15)
    AI_turn = False
    player_turn = True
def check():
    global correct_list, player_list, DEFEAT
    if len(correct_list) == len(player_list):
        if correct_list == player_list:
            return True
        else:
            DEFEAT = True
    return False
END_scr = True
running = True
AI_turn = True
player_turn = False
DEFEAT = False
score = 0
intro()
sleep(6)
while running:
    if AI_turn:
        sleep(.5)
        ai_turn()
    if player_turn:
        for event in pygame.event.get():
            if not DEFEAT:
                if event.type == pygame.QUIT:
                    running = False
                    END_scr = False
                if event.type == pygame.MOUSEBUTTONDOWN:
                    click()
                    if check():
                        AI_turn = True
                        player_turn = False
                        player_list = []
                        score += 1
                        break
            else:
                break
    if DEFEAT:
            break
scr.fill((0, 0, 0))
draw_text(scr, 'GAME OVER', 80, 225, 140)
draw_text(scr, ' SCORE ', 80, 225, 200)
draw_text(scr, str(score), 80, 225, 260)
pygame.display.update()
while END_scr:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            END_scr = False