import time

ti = time.time()
tempo = 255#512
tocadas = []
notas = {
	'\\':("SI_", 62.304), 
	'Z': ("DÓ",	66),
	'X': ("RÉ",	74.052),
	'C': ("MI",	83.16),
	'V': ("FA",	88.11),
	'B': ("SOL",	98.868),
	'N': ("LÁ",	111.01),
	'M': ("SI",	124.61),
	',': ("DÓ_",	132),
	'.': ("RÉ_",	148.1),
	';': ("MI_",	156.95),

	'A': ("Dó",	261.63), 
	'W': ("Dó#",	277.18), 
	'S': ("Ré",	293.66), 
	'E': ("Ré#",	311.13), 
	'D': ("Mi",	329.63), 
	'F': ("Fa",	349.23), 
	'T': ("Fa#",	369.99), 
	'G': ("Sol",	391.99), 
	'Y': ("Sol#",	415.3), 
	'H': ("Lá",	440), 
	'U': ("Lá#",	466.16), 
	'J': ("si",	493.88),
	'K': ("dó",	523.25), 
	'O': ("dó#",	554.37), 
	'L': ("ré",	587.33), 
	'P': ("ré#",	622.25), 
	'Ç': ("mi",	659.26),
	'~': ('fa',	698.5), 
	'[': ('fa#',	746.59), 
	']': ('sol', 790.94),
	
	"'": ('si_',	996.86),
	'1': ('dÓ',	1056),
	'2': ('rÉ',	1184.8),
	'3': ('mI',	1330.6),
	'4': ('fA',	1409.8),
	'5': ('sOL',	1581.9),
	'6': ('lÁ',	1776.2),
	'7': ('sI',	1993.7),
	'8': ('dó_',	2112),
	'9': ('ré_',	2369.7),
	'0': ('mi_',	2661.1),
	'-': ('fa_',	2819.5),
	'=': ('sol_',	3163.8)
}

quit = 'Q'

def tocar (mus, t = 0):
	if type(mus) == str:
		print('Tentando abrir arquivo', mus)
		mus = open(mus, 'r')		
	for n in mus:
		try:
			if type(n) == str:
				n = n.split() 
			dur = int(n[0])		
			ti = float(n[1])
			f = int(n[2])
		except Exception:	
			print('Erro em ', n)
		if ti - t > 1:			
			print((ti - t) / 60)	
		time.sleep(ti - t)	
		print(' {', n[-1], '}\t', n[-2],f,'\t',ti/60,dur//tempo)
		winsound.Beep(f, dur)
		t = ti + (dur / 1000)
		

import keyboard
import winsound

import sys

c = 1
r = False
while c < len(sys.argv):
	r = True
	print(c, sys.argv[c])	
	try:
		tocar(sys.argv[c])
		time.sleep(1/5)
	except KeyboardInterrupt:	
		print('Reprodução interrompida')
	except:	
		print('Erro inesperado')
	time.sleep(1/6)	
	c += 1
if r and not '#' in input('# para continuar: '):	
	exit(0)

n = quit
freq = 100
tocou = [0]
print('\aPiano:\n')



while True:
	try:
		if keyboard.is_pressed(n): 
			winsound.Beep(freq, tempo)
			tocou[0] += tempo
			continue
		for n in notas:
			if keyboard.is_pressed(n): 
				nota, freq = notas[n]
				freq = round(freq)
				t = time.time() - ti
				print(' (',n,')\t', nota, freq, ' \t', t / 60)
				winsound.Beep(freq, tempo)
				tocou = [tempo, t, freq, nota, n]
				tocadas.append(tocou)
				break		
		else:		
			n = quit
		if keyboard.is_pressed(quit): 		
			if input('Confirme se quer apagar a gravação de todas as %d notas tocadas até agora: digite * ' % len(tocadas))[-1] == '*':
				tocadas.clear()
				ti += t 
				print('Gravação apagada, tempo inicial adiantado', t, 's')
	except KeyboardInterrupt:
		print('\a')
		break
	except:
		print('Algo deu errado inesperadamente')
t = input('Você gostaria de: Repetir [&] e/ou Gravar [@]?')		
if '&' in t:
	print('A repetir %d notas:' % len(tocadas))
	tocar(tocadas)
if '@' in t:	
	t = input('Nome do arquivo:\n').strip()
	f = open(t, 'w')
	for t in tocadas:
		print(*t,file=f)
	
		
		
		
		