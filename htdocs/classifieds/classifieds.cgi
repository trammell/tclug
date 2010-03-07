#!/usr/bin/perl
######################################################################
# Mike's Classifieds
#
# version 1.1
# Please read the README for LICENSE information.  Do NOT remove the
# provided by a FREE script from mikespice.com from this script.
# 
# This program will act as a classifieds server.
# Please see the included README file for distrobution and copyright
# details.  Email mike@mikespice.com if you need more information
######################################################################

#use strict;
use CGI qw(:standard);
srand(); #generates randome seed.

#please edit the sitevariables.pl file to fit your site.
require "sitevariables.pl";

#begin main program
$cur = CGI->new();
printstarthtml();
print <<TABLE;
<table>
<tr valign="top">
<td width="180">
<table border=0>
<tr><td bgcolor="$tablecolor">Knoxville Classifieds</td></tr>
<tr><td><a href="$cgidir/classifieds.cgi">View Ads</a></td></tr>
<tr><td><a href="$cgidir/classifieds.cgi?place=yes">Place Ads</a></td></tr>
<tr><td bgcolor="$tablecolor">User Login/ Modify Ad</td></tr>
<tr><td><a href="$cgidir/classifieds.cgi?mode=delete">Delete Ad</a></td></tr>
<tr><td><a href="$cgidir/classifieds.cgi?mode=update">Update Ad</a></td></tr>
<tr><td bgcolor="$tablecolor">Help</td></tr>
<tr><td><a href="mailto:$myemail">E-Mail Webmaster</a></td></tr>
</table>
</td>
<td>
<center>
TABLE

if ($cur->param()) {
	if ($cur->param("place") eq "yes") {
		if ($cur->param("catagory")) {
			if ($cur->param("placecatagory")) {
				if ($cur->param("post") eq "yes") {
					takeandplacead();
				}else{
				$placecatagory=$cur->param("placecatagory");
				$catagory=$placecatagory;
				print "Catagory: $placecatagory";
				printpreview();
				}
			}else {
				$catagory=$cur->param("catagory");
				printformhtml();
			}
		} else {
			genplacetable();
		}
	} elsif ($cur->param("mode")) {
		$mode = $cur->param("mode");
		if($mode eq "delete") {
			printdeleteform();
		}
		if($mode eq "deletead") {
			$email = $cur->param("email");
			$password = $cur->param("password");
			$category = $cur->param("category");
			deletead();
		}
		if($mode eq "update") { #asks for user/pass
			print "Update an existing ad.";
			printupdateform();
		}
		if($mode eq "updatead") {
			printeditform();
		}
		if($mode eq "saveupdate") {
			saveupdate ();
		}
	
	} else {

		if ($cur->param("catagory")) {
			$catagory=$cur->param("catagory");
			open(DATAFILEIN,"$catagory.dat") || print "The $catagory catagory is empty!";
			print "<table border=1 width=\"500\">";
			while (<DATAFILEIN>) {
				chomp $_;
				@line_pair = split(/=/,$_);
				$time = $line_pair[0];
				$name = $line_pair[1];
				$email= $line_pair[2];
				$phone= $line_pair[3];
				$subject= $line_pair[4];
				$data= $line_pair[5];
				$data = &stripBadHtml($data);
				$pictureurl= $line_pair[7];
				print <<HTML;

<tr><td bgcolor="$tablecolor"><b>Subject: $subject</b> <div align=right>Posted: $time</div></td></tr>
<tr><td><b>Name: </b>$name<br>
<b>Email: </b><a href="mailto:$email">$email</a><br>
<b>Phone: </b>$phone<br>
<b>Description: </b>$data<br>
HTML
if($pictureurl) {
	print "<img src=\"$pictureurl\">";
}
print <<HTML;
</td></tr>
</td></tr>

HTML
			}
		print "</table>";
		}else{
			print "User did not specify a catagory!";
		}
	}
} else {
	gentable();

}
print <<TABLEEND;
</center>
</td>
</tr>
</table>
TABLEEND

printendhtml();

################ BEGIN SUBROUTINES ##################

#this subroutine prints out the header and basic info to generate an HTML file
sub printstarthtml {
print <<HTMLHEADER;
Content-type: text/html


<html>
<head>
    <title>$title</title>
     <style>
         <!--    
            A{text-decoration:none;font-weight:bold;}
          -->
     </style>
</head>
<body background="$htmldir/$background" text="#000000" bgcolor="#FFFFFF" link="#0000FF" vlink="#000080" alink="#FF0000">

<center><img SRC="$htmldir/$logo" ALT="Knoxville Classifieds"><hr><br></center>
HTMLHEADER

}

sub printendhtml {
print <<HTMLEND
<br><hr><font size=-1>Service provided by a FREE script from 
<a href="http://www.mikespice.com">MikeSpice.com</a>.  Copyright 2000 by MikeSpice.</font><br>
</body>
</html>
HTMLEND

}

sub dienice {
	my($msg) = @_;
	print <<HTML;
	<br>
<center><table width="400">
	<tr bgcolor="#FC3C3C"><td align="middle"><b><big>!! Oops !!</big></b></td></tr>
	<tr bgcolor="lightgrey"><td>$msg</td></tr>
</table></center></td></tr></table>
HTML
	printendhtml();
	exit;
}

#prints main catagory table
sub gentable{

	print "<table><tr><td bgcolor=\"$tablecolor\"><b>Browse Ads:</b><br>Please click on a link below
		to view the ads in that category.</td></tr>";
	print "<tr><td>";
	$index=0;
	foreach $cat (@catagories) {
		@line_pair = split(/=/,$cat);
		$catagorypicture = $line_pair[0];
		$catagorylink = $line_pair[1];
		$catagorydescription= $line_pair[2];
		print "<a href=\"$cgidir/classifieds.cgi?catagory=$catagorylink\" ><img src=\"$htmldir/$catagorypicture\" border=0></a>$catagorydescription<br>";
		$index++;
		if ($index==3) {
			$index=0;
			print <<END
			</td></tr><tr><td>
END
		}	
	}
	print "<\/td><\/tr></table>";

}

#prints main catagory table
sub genplacetable{

	print "<table border=0><tr><td bgcolor=\"$tablecolor\"><b>Place an Ad:</b><br>
			Please click on a category below to place an ad in that category.</td></tr>";
	print "<tr><td>";
	$index=0;
	foreach $cat (@catagories) {
		@line_pair = split(/=/,$cat);
		$catagorypicture = $line_pair[0];
		$catagorylink = $line_pair[1];
		$catagorydescription= $line_pair[2];
		print "<a href=\"$cgidir/classifieds.cgi?place=yes&catagory=$catagorylink\" ><img src=\"$htmldir/$catagorypicture\" border=0></a>$catagorydescription<br>";
		$index++;
		if ($index==3) {
			$index=0;
			print <<END
			</td></tr><tr><td>
END
		}	
	}
	print "<\/td><\/tr></table>";

}

#prints the html for 5the form to place an add.  Needs $placecatagory to put in as hidden.
sub printformhtml {
print <<FORM;

<FORM ACTION="$cgidir/classifieds.cgi">
<table>
<tr bgcolor="$tablecolor"><td colspan="2">Please fill out the following form</td></tr>
<tr>
	<td width="200">Name : </td>
	<td><INPUT TYPE="text" NAME="name" VALUE="" SIZE="30" MAXLENGTH="30"></td>
</tr>
<tr>
	<td width="200">Email : </td>
	<td><INPUT TYPE="text" NAME="email" VALUE="" SIZE="30" MAXLENGTH="30"></td>
</tr>
<tr>
	<td width="200">Phone : </td>
	<td><INPUT TYPE="text" NAME="phone" VALUE="" SIZE="30" MAXLENGTH="30"></td>
</tr>
<tr>
	<td width="200">Subject : </td>
	<td><INPUT TYPE="text" NAME="subject" VALUE="" SIZE="30" MAXLENGTH="50"></td>
</tr>
FORM
if($allowpictureurls eq 'YES') {
	print <<FORM;
<tr>
	<td valign="top" width="200">URL of picture (optional) :
	<font color="green"><br>example: http://www.mysite.com/picture.jpg</a></td>
	<td><INPUT TYPE="text" NAME="pictureurl" VALUE="" SIZE="30" MAXLENGTH="50"></td>
</tr>
FORM
}
print <<FORM;
<tr>
	<td valign="top" width="200">Description :</td>
	<td><TEXTAREA NAME="data" ROWS="3" COLS="30" wrap="soft">Please include price and description</TEXTAREA></td>
</tr>
<tr>
	<td colspan="2">
	<INPUT TYPE="hidden" NAME="catagory" VALUE="$catagory">
	<INPUT TYPE="hidden" NAME="placecatagory" VALUE="$catagory">
	<INPUT TYPE="hidden" NAME="place" VALUE="yes">
	<input type="submit" value="Preview Add!"></td>
<tr>
</table>
</FORM>

FORM
}


#This subroutine prints out a preview.  It needs $catagory to be set
sub printpreview {
$name=$cur->param("name");
$email=$cur->param("email");
$phone=$cur->param("phone");
$subject=$cur->param("subject");
$pictureurl=$cur->param("pictureurl");
$data=$cur->param("data");
$data=~s/\n/<br>/g;
$data = &stripBadHtml($data);
#some error checking

	if (!$name || !($email || $phone) || !$subject || !$data) {
		dienice("You did not fill out all of the required information.  You must
				include <br>1. your name<br>2. either an email or phone number
				<br>3. subject<br>4. and the content of the message<br><br>
				Please use your back button to correct this.");
	}
	if(($checkphonenumber eq 'YES') && $phone && !($phone =~ /^\(?[123456789][0-9]{2,2}\)?-?[0-9]{3,3}-?[0-9]{4,4}$/ )) {
		dienice("<br><br><br><center>Sorry, the phone number that you entered was not valid.
		Please enter it as <font color=red>xxx-xxx-xxxx</font> or 
		<font color=red>(xxx)xxx-xxxx</font> or <font color=red>xxxxxxxxxx</font>.<br><br> 
		Please use your browswers back button to make any corrections.</center>");
	}
	if($email && !($email =~ /[\w\-]+\@[\w\-]+\.[\w\-]+/)){
		dienice("<br><br><br><center>Sorry but the email you specified is not a valid email address.<br>
		We must have a valid email address in order to  
		notify you of any problems with your add.<br><br>
		<font color=red><b>Your email address will not be given to anyone or used 
		without your consent.</b></font><br><br>
		Please use your browswers back button to make any corrections.</center>");
	}


print <<FORM;

<FORM ACTION="$cgidir/classifieds.cgi"> Please use the back button to make any changes:
<br>
<INPUT TYPE="hidden" NAME="post" VALUE="yes">
<INPUT TYPE="hidden" NAME="catagory" VALUE="$catagory">
<INPUT TYPE="hidden" NAME="placecatagory" VALUE="$catagory">
<INPUT TYPE="hidden" NAME="place" VALUE="yes">
<INPUT TYPE="hidden" NAME="name" VALUE="$name">
<INPUT TYPE="hidden" NAME="email" VALUE="$email">
<INPUT TYPE="hidden" NAME="phone" VALUE="$phone">
<INPUT TYPE="hidden" NAME="subject" VALUE="$subject">
<INPUT TYPE="hidden" NAME="pictureurl" VALUE="$pictureurl">
<INPUT TYPE="hidden" NAME="data" VALUE="$data">

<table border=1 width="500">
<tr><td bgcolor="$tablecolor">Subject: $subject</td></tr>
<tr><td><b>Name: </b>$name<br>
<b>Email: </b><a href="mailto:$email">$email</a><br>
<b>Phone: </b>$phone<br>
<b>Description: </b>$data<br>
FORM
if($pictureurl) {
	print "<img src=\"$pictureurl\">";
}
print <<FORM;
</td></tr>
</td></tr>
</table>
<br><input type="submit" value="Post Add!">
</FORM> 

FORM
}

#This subroutine logs the user info in $htmldir/$catagory.log 
#it logs time,IP, Browser info, and whatever is in $subject
sub userlog {
	$time = localtime (time());
	$user = $ENV{"HTTP_USER_AGENT"};
	$ip = $ENV{"REMOTE_ADDR"};
#	print "<br>$ip voted at $time using $user<br>";
	if (open(LOGFILE,">>./$catagory.log")) {
		$log_line="$time" . "=" . "$ip" . "=" . "$user" . "=" . "$subject" . "\n";
		print LOGFILE $log_line;
		close LOGFILE;
	} else {
		print "There was an error opening the log file.  Please tell the webmaster.";
	}	
}


sub emailme {
	if ($cur->param("email")) {
$data =~ s/<br>/\n/g;
open (MAIL, "| /usr/lib/sendmail -oi -n -t" );
print MAIL <<MAIL_MESSAGE;
Subject: Your classified ad at $title
To:$toemail
From: $fromemail
$name,

Your classified ad at was placed $time.

Your add will run for $expire_after_days days.

Name: $name
Email: $email
Phone: $phone
Subject: $subject
Ad: $data

To view this and other ads at $title, please visit:
$cgidir/classifieds.cgi

If you would like to delete or change this add, please visit:
$cgidir/classifieds.cgi and use
Email: $email
Password: $password
(please save this email in case you need to delete or modify your ad)

Thank you,
$title
MAIL_MESSAGE

close MAIL;
	}
}

sub printdeleteform {
	print <<HTML;
<form method="post">
<table width="500">
	<tr bgcolor="$tablecolor">
		<td colspan="2">Please enter the email and password for the add.</td>
	</tr>
	<tr>
		<td colspan="2">If you cannot remember this information, please wait for $expire_after_days days 
		from the time you placed the ad and it will automatically be deleted.</td>
	</tr>
	<tr>
		<td>Category:</td>
		<td><select name="category">
HTML
	foreach $category (@catagories) {
		@entries = split(/=/,$category);
		$cat = $entries[1];
		print "<option value=\"$cat\">$cat</option>";
	}
	print <<HTML;		
		</select></td>
	</tr>
	<tr>
		<td>email (used to place ad):</td>
		<td><input type="text" name="email"></td>
	</tr>
	<tr>
		<td>password:</td>
		<td><input type="password" name="password"</td>
	</tr>
	<tr>
		<td colspan="2">
			<input type="hidden" name="mode" value="deletead">
			<input type="submit" value="Delete Ad">
		</td>
	</tr>
</table>
</form>
HTML
}

sub deletead {
	

	$count = 0;
	
	open(DATAFILEIN, "$category.dat") || dienice("Cound not open $category.dat");
	flock (DATAFILEIN, 2);
	while(<DATAFILEIN>) {
		@line_pair = split(/=/,$_);
		$password_file = $line_pair[8];
		$email_file = $line_pair[2];
		$password_file =~ s/\s//g; #gets rid of newline
		if((($password_file eq $password) && ($email_file eq $email))){
			$count++;
		} else {
			push (@temp,$_);
		}
	}
	flock (DATAFILEIN, 8);
					
	if (open(DATAFILEOUT, ">$category.dat") ) {
		flock (DATAFILEOUT, 2);
		print DATAFILEOUT @temp;
		flock (DATAFILEOUT, 8);
		print "<font color=\"red\">$count original ads have been deleted!</font><br><br>";
	} else {
		dienice("$category.dat could not be opened for writing.");
	}
}

sub printeditform {
	$email = $cur->param("email");
	$password = $cur->param("password");
	$category = $cur->param("category");
	$count = 0;
	
	open(DATAFILEIN, "$category.dat") || dienice("Cound not open $category.dat");
	flock (DATAFILEIN, 2);
	while(<DATAFILEIN>) {
		@line_pair = split(/=/,$_);
		$time = $line_pair[0];
		$name = $line_pair[1];
		$phone= $line_pair[3];
		$subject= $line_pair[4];
		$data= $line_pair[5];
		$time2 = $line_pair[6];
		$pictureurl= $line_pair[7];
		$password_file = $line_pair[8];
		$email_file = $line_pair[2];
		$password_file =~ s/\s//g; #gets rid of newline
		if((($password_file eq $password) && ($email_file eq $email))){
			foundadeditform();
			$count++;
		}
	}
	flock (DATAFILEIN, 8);
	print "$count ads found with that username/pass";
}

sub foundadeditform {
print <<FORM;

<FORM ACTION="$cgidir/classifieds.cgi">
<table>
<tr bgcolor="$tablecolor"><td colspan="2">Please make any changes and click update.<br>
	Please note: after making changes, your original ad will be deleted and this add will
	run for an additional $expire_after_days days.</td></tr>
<tr>
	<td width="200">Name : </td>
	<td><INPUT TYPE="text" NAME="name" VALUE="$name" SIZE="30" MAXLENGTH="30"></td>
</tr>
<tr>
	<td width="200">Email : </td>
	<td><INPUT TYPE="text" NAME="email_form" VALUE="$email_file" SIZE="30" MAXLENGTH="30"></td>
</tr>
<tr>
	<td width="200">Phone : </td>
	<td><INPUT TYPE="text" NAME="phone" VALUE="$phone" SIZE="30" MAXLENGTH="30"></td>
</tr>
<tr>
	<td width="200">Subject : </td>
	<td><INPUT TYPE="text" NAME="subject" VALUE="$subject" SIZE="30" MAXLENGTH="50"></td>
</tr>
FORM
if($allowpictureurls eq 'YES'){
print <<FORM;
<tr>
	<td valign="top" width="200">URL of picture (optional) :
	<font color="green"><br>example: http://www.mysite.com/picture.jpg</a></td>
	<td><INPUT TYPE="text" NAME="pictureurl" VALUE="$pictureurl" SIZE="30" MAXLENGTH="50"></td>
</tr>
FORM
}
print <<FORM;
<tr>
	<td valign="top" width="200">Description :</td>
	<td><TEXTAREA NAME="data" ROWS="3" COLS="30" wrap="soft">$data</TEXTAREA></td>
</tr>
<tr>
	<td colspan="2">
	<INPUT TYPE="hidden" NAME="mode" VALUE="saveupdate">
	<INPUT TYPE="hidden" NAME="email" VALUE="$email">
	<INPUT TYPE="hidden" NAME="password" VALUE="$password">
	<INPUT TYPE="hidden" NAME="category" VALUE="$category">
	<INPUT TYPE="hidden" NAME="catagory" VALUE="$category">
	<input type="submit" value="Update Add!"></td>
<tr>
</table>
</FORM>

FORM
}


sub printupdateform {
	print <<HTML;
<form method="post">
<table width="500">
	<tr bgcolor="$tablecolor">
		<td colspan="2">Please enter the email and password for the add.</td>
	</tr>
	<tr>
		<td colspan="2">If you cannot remember this information, please wait for $expire_after_days days 
		from the time you placed the ad and it will automatically be deleted.</td>
	</tr>
	<tr>
		<td>Category:</td>
		<td><select name="category">
HTML
	foreach $category (@catagories) {
		@entries = split(/=/,$category);
		$cat = $entries[1];
		print "<option value=\"$cat\">$cat</option>";
	}
	print <<HTML;		
		</select></td>
	</tr>
	<tr>
		<td>email (used to place ad):</td>
		<td><input type="text" name="email"></td>
	</tr>
	<tr>
		<td>password:</td>
		<td><input type="password" name="password"</td>
	</tr>
	<tr>
		<td colspan="2">
			<input type="hidden" name="mode" value="updatead">
			<input type="submit" value="Update Ad">
		</td>
	</tr>
</table>
</form>
HTML
}

sub saveupdate {

	$email = $cur->param("email");
	$password = $cur->param("password");
	$category = $cur->param("category");
	print "First, your original ad will be deleted, then your new ad will be posted.<br><br>";
	deletead();
	takeandplacead();
	
}

sub takeandplacead {
	$time = localtime (time());
	$catagory=$cur->param("catagory");
	$name=$cur->param("name");
	$email=$cur->param("email");
	if($mode eq "saveupdate"){
		$email = $cur->param("email_form");
	}
	$phone=$cur->param("phone");
	$subject=$cur->param("subject");
	$pictureurl=$cur->param("pictureurl");
	$data=$cur->param("data");
	$data=~s/\n/<br>/g;
	$expiretime = time();
	$password = int(rand(1000000));
	my @temp;
	open(DATAFILEIN, "$catagory.dat") || print "Your add is the first in this catagory!<br>";
	flock (DATAFILEIN, 2);
	while(<DATAFILEIN>) {
		@line_pair = split(/=/,$_);
		$time2 = $line_pair[6];
		$currenttime = time ();
		$difference = $currenttime - $time2;
		#computing the number of seconds before it expires
		$expires = $expire_after_days * 86400;
		if($difference < $expires){
			push (@temp,$_);
		}
		
	}
	flock (DATAFILEIN, 8);
	if (open(DATAFILEOUT, ">$catagory.dat") ) {
		flock (DATAFILEOUT, 2);
		print DATAFILEOUT "$time=$name=$email=$phone=$subject=$data=$expiretime=$pictureurl=$password\n";
		print DATAFILEOUT @temp;
		userlog();
		if ($emailme eq "yes") {
			$toemail = $myemail;
			$fromemail = $email;
			emailme();
		}
		if ($emailuser eq "yes") {
			$toemail = $email;
			$fromemail = $myemail;
			emailme();
		}
		flock (DATAFILEOUT, 8);
		print "Your add has been placed!<br><br>It will expire after $expire_after_days days.
		<br><br>Your ad password: <b>$password</b>
		<br><br>Please write this down.  You will need to keep this password to modify or
		delete your ad (or it will automatically be deleted after $expire_after_days days).";
	}else {
		print "$catagory.dat could not be opened for writing!";
	}
}

#####################################################3
#subs from slashdot to remove bad html
#####################################################
# Thanks to Slashdot for these
# Approved HTML tags for HTML posting
@approvedtags = (
        'B','I','P .*','P','A',
        'LI','OL','UL','EM','BR',
        'STRONG','BLOCKQUOTE',
        'HR','DIV .*','DIV','TT'
        );

sub stripBadHtml
{
        my ($str) = @_;

        $str =~ s/(\S{90})/$1 /g;
        $str =~ s/<(?!.*?>)//;
        $str =~ s/<(.*?)>/approvetag($1,@approvedtags)/sge; #replace
tags with approved ones
        return $str;
}

sub approvetag
{
        my ($tag,@apptag) = @_;

        $tag =~ s/^\s*?(.*)\s*?$/$1/e; #trim leading and trailing spaces

        if (uc(substr ($tag, 0, 2)) eq 'A ')
        {
                $tag =~ s/^.*?href="?(.*?)"?$/A HREF="$1"/i; #enforce "s
                return "<" . $tag . ">";
        }

        foreach my $goodtag (@apptag)
        {
                $tag = uc $tag;
                if ($tag eq $goodtag || $tag eq '/' . $goodtag)
                        {return "<" . $tag . ">";}
                #check against my list of tags
        }
        return "";
}

