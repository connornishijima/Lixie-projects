<?php
	/*************************************************************************
	php easy :: online visitors counter scripts set - PHP Include Version
	==========================================================================
	Modified by Connor Nishijima to allow read-only count viewing
	Author: php easy code, www.phpeasycode.com
	Web Site: http://www.phpeasycode.com
	Contact: webmaster @ phpeasycode.com
	*************************************************************************/

	$dbfile = "visitors.db"; // path to data file
	$expire = 120; // average time in seconds to consider someone online before removing from the list
	 
	if(!file_exists($dbfile)) {
		die("Error: Data file " . $dbfile . " NOT FOUND!");
	}
	 
	if(!is_writable($dbfile)) {
		die("Error: Data file " . $dbfile . " is NOT writable! Please CHMOD it to 666!");
	}
	 
	function CountVisitors() {
		global $dbfile, $expire;
		$cur_ip = getIP();
		$cur_time = time();
		$dbary_new = array();
	 
		$dbary = unserialize(file_get_contents($dbfile));
		if(is_array($dbary)) {
			while(list($user_ip, $user_time) = each($dbary)) {
				if(($user_ip != $cur_ip) && (($user_time + $expire) > $cur_time)) {
					$dbary_new[$user_ip] = $user_time;
				}
			}
		}
			
		if(isset($_GET["read"]) == false){
			$dbary_new[$cur_ip] = $cur_time; // add record for current user
		
			$fp = fopen($dbfile, "w");
			fputs($fp, serialize($dbary_new));
			fclose($fp);
		}
		return count($dbary_new);
	}
	 
	function getIP() {
		if(isset($_SERVER['HTTP_X_FORWARDED_FOR'])) $ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
		elseif(isset($_SERVER['REMOTE_ADDR'])) $ip = $_SERVER['REMOTE_ADDR'];
		else $ip = "0";
		return $ip;
	}
	 
	echo CountVisitors();
?>
