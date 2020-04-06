from fractions import gcd


def simplify(frac):
	nwd = gcd(frac[0], frac[1])
	frac[0] /= nwd
	frac[1] /= nwd
	return frac


def add_frac(frac1, frac2):
	if frac1[1] == frac2[1]:
		return simplify([frac1[0] + frac2[0], frac1[1]])
	else:
		mianownik = frac1[1] * frac2[1]
		licznik = (frac1[0] * frac2[1]) + (frac2[0] * frac1[1])
		return simplify([licznik, mianownik])


def sub_frac(frac1, frac2):
	if frac1[1] == frac2[1]:
		return simplify([frac1[0] - frac2[0], frac1[1]])
	else:
		mianownik = frac1[1] * frac2[1]
		licznik = (frac1[0] * frac2[1]) - (frac2[0] * frac1[1])
		return simplify([licznik, mianownik])


def mul_frac(frac1, frac2):
	return simplify([frac1[0] * frac2[0], frac1[1] * frac2[1]])


def div_frac(frac1, frac2):
	return simplify([frac1[0] * frac2[1], frac1[1] * frac2[0]])


def is_positive(frac):
	if (frac[0] * frac[1]) > 0:
		return True


def is_zero(frac):
	if frac[0] == 0:
		return True
	else:
		return False


def cmp_frac(frac1, frac2):
	if frac2float(frac1) > frac2float(frac2):
		return 1
	elif frac2float(frac1) == frac2float(frac2):
		return 0
	else:
		return -1


def frac2float(frac):
	return float(frac[0])/float(frac[1])
