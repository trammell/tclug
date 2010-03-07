# Edit these variables to fit your site.

#This is the tilte for the HTML page
$title="Mikes Classifieds";

#this is the image file displayed at the top of each page.  It should be in the $htmldir
$logo="logo.jpg";

# this should be the image that you want to use as a backgroound and should be in $htmldir
$background = "background.jpg";

#this should point to a directory for the  data files to be written
#and the permissions should be set to 775 for this folder. This is actually the directory
#that web browsers point to get to your CGI files.  More than likely, 
#you will have cgi-bin directory in your main web directory so
#just make a classifieds directory in there.
$cgidir = "http://www.mikespice.com/cgi-bin/classifieds";

#this should point to the web address of the data files as a browser would point to them
$htmldir = "http://www.mikespice.com/classifieds";

#this should be the HEX code for the color that you want on your tables
$tablecolor = "#FF9900";

#change this to "yes" if you wish the user to be mailed when 
# they post an add
$emailuser = "no";

# change this to "yes" if you wish to be emailed each time someone 
# places an ad.
$emailme = "no";

# change this to your email if you put yes above so that the script
# can email you.
$myemail = 'email@provider.com';

#the number of days before an add expires and is automatically delted
$expire_after_days = 14;

#set this to 'YES' if you would like the user to be able to enter
#a url to a picture for the ad.  When this is set to 'YES' some
#users could enter non-existing URL's and others could put
#pictures with a large filesize causing the page to take a long
#time to load.  For this reason, it is diabled by default
$allowpictureurls = 'NO';

#set this to 'YES' if you would like to check the phone number to
#see if it is a valid USA number.  Change this to 'NO' and it will
#not be checked.  Please set this to 'NO' if you are not in the USA.
$checkphonenumber = 'YES';

# please edit and add catagories as shown.  For example, if you wanted 
#to add a catagory called Food and had a picture called food.gif in the 
#$htmldir, then you would add a "food.gif=Food - description of the catagory", 
#to the array.
@catagories = (
"auto.gif=auto=Autos - cars,trucks,motorcycles,more",
"computer.gif=computer=Computers - parts,services",
"love.gif=love=Personals",
"merchandise.gif=merchandise=General Merchandise",
"rental.gif=rental=Houses/Appartments/Roomates");

############ end of variables and such ################################

return 1;
