#include "gigasecond.h"
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::posix_time;

namespace gigasecond
{
    const seconds oneGigaSecond = seconds(1000000000);
    ptime advance(ptime time)
    {
        return time + oneGigaSecond;
    }
} // namespace gigasecond
