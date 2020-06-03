dnevnik = {'Luka' : 10,'Sandra' : 1}

print(dnevnik)
print(type(dnevnik))

print(dnevnik.keys())
print(dnevnik.values())
print("\n")


print(sorted(dnevnik.keys()))

dnevnik['Sandra'] = 7
print(dnevnik, end ='\n')

print(dnevnik.get("Trifunovic"))

if 'Sonja' not in dnevnik.ke():
	dnevnik['Sonja'] = 3;
else:
	print(dnevnik['Sonja'],'\n')
