package main

import (
 "fmt"
 "math/rand"
)

func algorithm1(roundNumber int, own, enemy []bool)bool {
 if roundNumber == 0 {
  return true
 } else {
   return false
 }
}

func algorithm2(roundNumber int, own, enemy []bool) bool{
 return rand.Intn(2)==1 
}

func algorithm3(roundNumber int, own, enemy []bool)bool {
 if (roundNumber > 0) && (enemy[roundNumber - 1]== false) {
    return true
 } else{
    return false
 }
}

func main() {
 n := rand.Intn(101) + 100
 first := make([]bool, n)
 second := make([]bool, n)
 check1 := 0
 check2 := 0

 for i := 0; i < n; i++ {
  first[i]=algorithm2(i, first, second)
  second[i]=algorithm3(i, second, first)

  if first[i] && second[i] {
   check1 += 24
   check2 += 24
  } else if first[i] && !second[i] {
   check1 += 0
   check2 += 20
  } else if !first[i] && second[i] {
   check1 += 20
   check2 += 0
  } else if !first[i] && !second[i] {
   check1 += 4
   check2 += 4
  }
  fmt.Println(first[i], second[i], check1, check2)
 }
}
