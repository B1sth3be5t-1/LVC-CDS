# pip install pgeocode
# OR
# add pgeocode to requirements.txt
import pgeocode

nomi = pgeocode.Nominatim('us')
print(nomi.query_postal_code('17003'))

dist = pgeocode.GeoDistance('us')
applicant_zip = '17821'
dist_miles = dist.query_postal_code('17003', applicant_zip) / 1.609
print(dist_miles)
