// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#define _DEBUG 1

#define PHP_RECEIVE "y-less.com/YSI/web/YSI_receive.php"
#define PHP_SEND    "y-less.com/YSI/web/YSI_send.php"

#include <a_samp>
#include <YSI\y_php>

#include <YSI\y_testing>

Test:Send0()
{
	PHP_SendString("First", "first", true);
}

Test:Send1()
{
	PHP_SendString("First", "yeah");
	PHP_SendInt("First", 42);
	PHP_SendFloat("First", 7.2);
	PHP_SendBool("First", true);
}

