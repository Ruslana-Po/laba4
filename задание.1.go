
package main

import (
 "fmt"
 "math"
)

const E = 0.0001

func f(x float64) float64 {
 return x*math.Log(x+1) - 1
}
//1 производ
func f1(x float64) float64 {
 return x/(x+1) + math.Log(x+1)
}

func halfDivision(a, b float64) {
 if f(a)*f(b) >= 0.0 {
  fmt.Println("Неверный интервал")
  return
 }
 k := 0
 var c float64
 for math.Abs(b-a) >= E {
  fmt.Printf("%7d|%8.4f | %8.4f|%f\n", k, a, b, b-a)
  c = (a + b) / 2
  if f(c) == 0.0 {
   break
  } else if f(c)*f(a) < 0 {
   b = c
  } else {
   a = c
  }
  k++
 }

 fmt.Printf("Корень %f с %d итерациями\n", c, k)
}

func newtonMethod(a, b int, x0 float64) {
 if f(float64(a))*f(float64(b)) >= 0.0 {
  fmt.Println("Неверный интервал ")
  return
 }
 k := 0
 x1 := x0 - f(x0)/f1(x0)
 for math.Abs(x1-x0) >= E {
  fmt.Printf("%7d|%8.4f | %8.4f|%f\n", k, x0, x1, x1-x0)
  x0 = x1
  x1 = x0 - f(x0)/f1(x0)
  k++
 }
 fmt.Printf("Корень %f с %d итерациями\n", x0, k)
}

func simpleIterations(x0 float64) {
 k := 0
 x1 := 1 / math.Log(x0+1)
 for math.Abs(x1-x0) > E {
  fmt.Printf("%7d|%8.4f | %8.4f|%f\n", k, x0, x1, x1-x0)
  x0 = x1
  x1 = 1 / math.Log(x0+1)
  k++
 }
 fmt.Printf("Корень %f с %d итерациями\n", x0, k)
}

func main() {
 fmt.Println("программу уточнения корня методом половинного деления с точностью до E")
 halfDivision(-1, 1)
 fmt.Println("\nпрограмму уточнения корня Ньютона с точностью до E")
 newtonMethod(-10, 10, 10)
 fmt.Println("\nметода простых итераций")
 simpleIterations(2)
}
