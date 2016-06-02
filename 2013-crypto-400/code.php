<?php
// h4x0r's ultimate encryption algorithm
// I put the string to be encrypted here
$str = 'samplestringasdcfa';

// I convert the string to ASCII

for ($i = 0; $i<strlen($str); $i++)
   $dec_array[] = ord($str{$i});
$ar = $dec_array;
$max = max($ar);

// I generate a random key in between 10 and the maximum value of the ASCII's
// So the key is different everytime B)

$key = rand(10,$max);

// Multiply the key by 101 to increase complexity

$key = 101*50;

// Using this key I encrypt my string using the cool algorithm below

for($i=0;$i<strlen($str);$i++)
{
	$x = $ar[$i];
	$am = ($key+$x)/2;
	$gm = sqrt($key*$x);
	$enc = $am + $gm;


	$encrypt = floor($enc)%255; // This is the final encrypted number
	
	print $am.' '.$x.' '.$gm.' '.$enc.' ';	
	// the numbers are printed 
	echo $encrypt.' '."\n";
}
print "\n";
?>
