#!/usr/bin/env python

#import modules
import pygame
import math
import csv
import time

#initialize pygame
pygame.init()

#CLock
clock = pygame.time.Clock()

#RGB Colours
RED = (255,0,0)
BLACK = (0,0,0)
WHITE = (255,255,255)

#Set up Window
wn_width = 600
wn_height = 600
wn = pygame.display.set_mode((wn_width, wn_height))
pygame.display.set_caption("DFS")

pygame.draw.rect(wn ,RED, (240,240,180,180))

#function to display dot
def display_dot(info):

	x = int(info[0])
	y = int(info[1])

	pygame.draw.circle(wn, WHITE, (x, y), 7)

#function to display line
def display_line(info, prev_info):

	x = int(info[0])
	y = int(info[1])
	prev_x = int(prev_info[0])
	prev_y = int(prev_info[1])

	pygame.draw.line(wn, WHITE, (x, y), (prev_x, prev_y), 2)

#access csv file
with open('/home/ashd/gazebo_ws/src/stc/src/scripts/path.csv', 'r') as csv_file:
	reader = csv.reader(csv_file, delimiter = ',')
	info = next(reader)
	prev_info=info

	state = True
	while state:
		for event in pygame.event.get():
			if event.type==pygame.QUIT:
				state = False

		try:
			display_dot(info)
			display_line(info, prev_info)
			prev_info=info
			info = next(reader)

		except:
			break

	
		pygame.display.flip()
		time.sleep(0.1)

csv_file.close()

while True:
	pass