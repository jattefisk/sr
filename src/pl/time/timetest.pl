#!/usr/bin/perl

use POSIX;
use File::Copy;

umask(0117);
system("setenv", "TZ", "UTC+00:00", "1");

$my_date = strftime("%y%m%d", localtime);
$my_doy = strftime("%j", localtime);

#$yourDate1 = strftime("%y%m%d", 0, 0, 0, 31, 11, 95, 0, 0);
#$yourDate2 = strftime("%y%m%d", 0, 0, 0, 32, 11, 95, 0, 0);

$dy = strftime("%d", localtime);
$mo = strftime("%m", localtime);
$yr = strftime("%y", localtime);

$mo = 10;
$dy = 31;

$to = strftime("%y%m%d", 0, 0, 0, ($dy + 1), ($mo - 1), $yr, 0, 0);

print "today\t\t[$yr$mo$dy]\n";
print "tomorrow\t[$to]\n";

#print "$my_date is the $my_doy day of the year\n";
#print "yourDate1[$yourDate1]\n";
#print "yourDate2[$yourDate2]\n";

