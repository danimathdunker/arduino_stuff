/*  read_humi - read humidity
 *
 *  2016-06-22   Andreas Dunker   created
 *
 ************************************************************************/

void read_humi ()
{
	fHumidity = hdc.readHumidity ();
}

