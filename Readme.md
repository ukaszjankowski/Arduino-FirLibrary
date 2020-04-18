# Arduino FIR filter library

C++ template for finite impulse response filter

## Usage:

```
#include "Fir.h"

Fir <30, float> fir(0);

for (;;) {
  float measurement = getMeasurement();
  fir.Push(measurement);
  float filteredValue = fir.Get();
  saveMeasurement(filteredValue);
}
```

## More info about filter:
https://en.wikipedia.org/wiki/Finite_impulse_response

## License

This software is released under GNU GPL 3 licesne. See LICENSE file for more details.

## Author

Łukasz Jankowski
