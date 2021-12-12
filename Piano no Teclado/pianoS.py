import time

ti = time.time()
tempo = 255#512
tocadas = []
notas = {
	'A': ("D",	262), 
	'W': ("D#",	277), 
	'S': ("R",	294), 
	'E': ("R#",	311), 
	'D': ("M",	330), 
	'F': ("F",	349), 
	'T': ("F#",	370), 
	'G': ("S",	392), 
	'Y': ("S#",	415), 
	'H': ("L",	440), 
	'U': ("L#",	466), 
	'J': ("s",	494),
	'K': ("d",	523), 
	'O': ("d#",	554), 
	'L': ("r",	587), 
	'P': ("r#",	622), 
	'Ç': ("m",	659)
}

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
		print(' [', n[-1], ']\t', n[-2],f,'\t',ti/60,dur//tempo)
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

n = 'Q'
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
				t = time.time() - ti
				print(' [',n,']\t', nota, freq, ' \t', t / 60)
				winsound.Beep(freq, tempo)
				tocou = [tempo, t, freq, nota, n]
				tocadas.append(tocou)
				break
		if keyboard.is_pressed('Q'): 		
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
	
		
		
		
		