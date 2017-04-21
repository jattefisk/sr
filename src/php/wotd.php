<?php

function make_curl_call($uri, array $opts = array()) {
    $ch = curl_init($uri);
    curl_setopt_array($ch, $opts);
    $output = curl_exec($ch);
    curl_close($ch);

    return ($output);
}

function get_a_word() {
    $opts = array(
//	CURLOPT_URL		=> "http://www.setgetgo.com/randomword/get.php",
	CURLOPT_URL		=> "http://randomword.setgetgo.com/get.php",
	CURLOPT_FOLLOWLOCATION	=> TRUE,
	CURLOPT_RETURNTRANSFER	=> TRUE
    );

    $ch = curl_init();
    curl_setopt_array($ch, $opts);
    $output = curl_exec($ch);
    curl_close($ch);

    return ($output);
}

/**
 * Need an API key from Mashape for WordsAPI
 */
function get_definition($word) {
    $opts = array(
	CURLOPT_URL		=> "https://wordsapiv1.p.mashape.com/words/" . $word . "/definitions",
	CURLOPT_FOLLOWLOCATION	=> TRUE,
	CURLOPT_RETURNTRANSFER	=> TRUE
    );

    $ch = curl_init();
    curl_setopt_array($ch, $opts);
    $output = curl_exec($ch);
    curl_close($ch);

    return ($output);
}

$wotd = get_a_word();
print ("Word of the Day:\t" . $wotd . "\n");
// $def = get_definition("leeward");
// print("Definition:\t" . $def . "\n");
?>
