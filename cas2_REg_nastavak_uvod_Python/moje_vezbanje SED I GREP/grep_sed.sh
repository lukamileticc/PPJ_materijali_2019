
egrep '<td>\s*[A-Z][a-z]+ [A-Z][a-z]+\s*</td>\s*<td>([1-9][0-9]?|[12][0-9]{2}|3[0-4][0-9]|350)/20(0[0-9]|1[0-6])</td>' nastava*.html -h | sed -r 's/\s*<td>([A-Za-z ]+)<\/td>\s*<td>([0-9\/]+)<\/td>.*/\1, \2/' |
sed -r 's/\b([1-9])\b/00\1/' |
sed -r 's/\b([1-9][0-9])\b/0\1/' |
sed -r 's/([0-9]{3})\/20([0-9]{2})/mi\2\1/' |
sed -r 's/(\w+) (\w+)/\2 \1/' | sort |
egrep '.*' -n | sed -r 's/:/. /'
