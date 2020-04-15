# Dude, is my code constant time?

- Measure execution time

    - Two different input classes: ***fix*** and ***random***
    - Used the modern function provided by CPU: cycle counters to measure execution time accurately
    - The class of each measurement is random, and the input will be done before the measurement to reduce the environmental impacts


- Post processing
    - Cropping: Exclude extreme values due to OS or other unrelated factors
    - Higher-order preprocessing: Adjust the system based on different statistical tests
    - Statistical Test
      - Welch's T-test: It is a T-test method to 
      - Non-parametric test: I need to do further study on this too

``` C
#define number_tests                                                           \
  (1 /* first order uncropped */ + number_percentiles /* cropped */ +          \
   1 /* second order uncropped */)
#define enough_measurements 10000 // pretty arbitrary
#define number_percentiles 100
static t_ctx *t[number_tests];
static int64_t percentiles[number_percentiles] = {0};

// threshold values for Welch's t-test
#define t_threshold_bananas 500 // test failed, with overwhelming probability
#define t_threshold_moderate 10 // test failed. Pankaj likes 4.5 but let's be more lenient
```

``` C
if (max_t > t_threshold_bananas) {
    printf(" Definitely not constant time.\n");
    exit(0);
  }
  if (max_t > t_threshold_moderate) {
    printf(" Probably not constant time.\n");
  }
  if (max_t < t_threshold_moderate) {
    printf(" For the moment, maybe constant time.\n");
  }
}
```


```
meas: 2916.21 M, max t: +500.04, max tau: 9.26e-03, (5/tau)^2: 2.92e+05. Definitely not constant time.
```
