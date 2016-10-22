#!/usr/bin/perl

@myArray = ('one', 'two', 'three', 'four');

$myItem = shift(@myArray);

print STDOUT "myItem[$myItem]\n";
print STDOUT "myArray[@myArray]\n";

$myItem = pop(@myArray);
print STDOUT "myItem[$myItem]\n";
print STDOUT "myArray[@myArray]\n";

@myArray = ('one', 'two', 'three', 'four');

while ($myItem = shift(@myArray)) {
	print STDOUT "$myItem\n";
}
