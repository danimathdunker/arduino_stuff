/*  read_clock - read clock
 *
 *  2016-06-22   Andreas Dunker   created
 *
 ************************************************************************/

void read_clock ()
{
	bool h12;
    bool PM;

    hours   = Clock.getHour (h12, PM);
    minutes = Clock.getMinute ();
    seconds = Clock.getSecond ();
}


