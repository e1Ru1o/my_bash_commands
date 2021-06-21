import re

FORMAT = '%s\n%02d:%02d:%02d,%d --> %02d:%02d:%02d,%d\n%s'
REGEX  = r'^(\d+)[\n](\d+):(\d+):(\d+),(\d+) --> (\d+):(\d+):(\d+),(\d+)[\n]((?:.+[\n])*)'

def get_time(h, m, s, ms, add):
	d = []
	n = int(h) * 3600000 + int(m) * 60000 + int(s) * 1000 + int(ms) + add
	for i in [1000, 60, 60]:
		d.append(n % i)
		n //= i
	d.append(n)
	d.reverse()
	return d

def advance_sub(text, add):
	output = []
	data = re.findall(REGEX, text, flags=re.MULTILINE)
	# print(data)
	for (id, sh, sm, ss, sms, eh, em, es, ems, txt) in data:
		start = get_time(sh, sm, ss, sms, add)
		end   = get_time(eh, em, es, ems, add)  
		output.append(FORMAT % (id, *start, *end, txt))
	print('\r\n'.join(output))

def main(args):
	file = args.file
	add  = args.add if not args.n else -args.add
	text = open(file, 'rb').read().decode(encoding='unicode_escape')
	# print(text)
	advance_sub(text, add)

if __name__ == "__main__":
	import argparse

	parser = argparse.ArgumentParser(description='Sub updater')

	parser.add_argument('-f', '--file', type=str, required=True, help='subs file')
	parser.add_argument('-a', '--add' , type=int, required=True, help='update time')
	parser.add_argument('-n', help='negative update', action="store_true")

	args = parser.parse_args()
	main(args)
