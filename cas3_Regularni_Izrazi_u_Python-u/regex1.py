import sys,re

poruka = "Danas je divan dan"

matcher = re.match(r"(?i)(\w+\s*)+",poruka)

if matcher is not None:
	print(matcher.group())
else:
	print("Sablon se ne nalazi u tekstu!")


m = re.search(r"\b(d([a-z]+))",poruka,re.S)

if m is not None:
	print(m.group())

	print(poruka[m.start():m.end()])

	print(m.group(1,2))

	print(m.groups())

m = re.search(r"\bd([a-z]+)",poruka[m.end():],re.S)

if m is not None:
	print(m.group())
	print(m.group(1))
	print(m.groups())


reci = re.findall(r"\b(d([a-z]+))",poruka,re.S|re.I)

if reci is not None:
	print(reci)

print(re.sub(r"(?i)\b(d([a-z]+))",r"\2--\1",poruka))
