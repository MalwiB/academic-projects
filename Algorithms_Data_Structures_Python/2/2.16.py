# 2.16
# zamienic w tekscie CIAG ZNAKOW (nie slowo) GvR na Guido van Rossum
# wystarczy tylko funkcja replace()

line = "inne slowa inne GvR inne"

replaced = line.replace("GvR", "Guido van Rossum")

print "Przed podstawieniem: "
print line + '\n'
print "Po podstawieniu: "
print replaced