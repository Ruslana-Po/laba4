
package main

import (
 "fmt"
 "math/rand"
 "sort"
)

const n = 12
//Склейка
func connect(arr1, arr2 []int) {
 for i := 0; i < n; i++ {
  if i >= 0 && i <= 5 {
   temp := arr1[i]
   arr1[i] = arr2[i+(n/2)]
   arr2[i+(n/2)] = temp
  } else {
   temp := arr1[i]
   arr1[i] = arr2[i]
   arr2[i] = temp
  }
 }
}
//Вывод
func conclusion(arr []int) {
 for i := 0; i < n; i++ {
  fmt.Print(arr[i], " ")
 }
}
//Простые числа
func sieveEratosthenes() []int {
 var numberProst []int
 numberProst = append(numberProst, 2)
 for i := 3; i <= 30; i++ {
  k := 0
  for j := 0; j < len(numberProst); j++ {
   if i%numberProst[j] == 0 {
    k++
   }
  }
  if k == 0 {
   numberProst = append(numberProst, i)
  }
 }
 return numberProst
}
//Проверка простых чисел
func examination(arr []int, numberProst []int) {
 for i := 0; i < n; i++ {
  for j := 0; j < len(numberProst); j++ {
   if arr[i] == numberProst[j] {
    fmt.Print(arr[i], " ")
   }
  }
 }
}
//Повтор цифор
func repeat(arr1 []int) []int {
 var arr2 []int
 j := 0
 x := make([]int, 4)
 for i := 0; i < n; i++ {
  c := arr1[i]
  kol := 0
  for c > 0 {
   x[kol] = c % 10
   c /= 10
   kol++
  }
  counter := 0
  for z := 0; z < 3; z++ {
   for y := z + 1; y < 4; y++ {
    if x[z] == x[y] {
     counter++
     break
    }
   }
   if counter > 0 {
    break
   }
  }
  if counter == 1 {
   arr2 = append(arr2, arr1[i])
   j++
  }
 }
 return arr2
}
//Замена решгистра
func replacement(arr []byte) {
 for i := 0; i < n; i++ {
  if arr[i] >= 'A' && arr[i] <= 'Z' {
   arr[i] += 32
  } else if arr[i] >= 'a' && arr[i] <= 'z' {
   arr[i] -= 32
  }
 }
}

func main() {
 arr1 := make([]int, n)
 arr2 := make([]int, n)
 // Задание 1
 for i := 0; i < n; i++ {
//рандом от 10 до 100
  arr1[i] = rand.Intn(91) + 10
  arr2[i] = rand.Intn(91) + 10
 }
 fmt.Print("arr1: ")
 conclusion(arr1)
 fmt.Println("\narr2: ")
 conclusion(arr2)

 // Задание 2
 fmt.Println("\nПоиск простых элементов от 0-30:")
 numberProst := sieveEratosthenes()
 fmt.Print("arr1: ")
 examination(arr1, numberProst)
 fmt.Print("\narr2: ")
 examination(arr2, numberProst)

 // Задание 3
 fmt.Println("\nОтсортерованные массивы:")
 //сортировка
 sort.Ints(arr1[:n/2])
 sort.Sort(sort.Reverse(sort.IntSlice(arr2[n/2:n])))
 fmt.Print("arr1: ")
 conclusion(arr1)
 fmt.Print("\narr2: ")
 conclusion(arr2)
 connect(arr1, arr2)
 fmt.Println("\nСмена отсортированных элементов:")
 fmt.Print("arr1: ")
 conclusion(arr1)
 fmt.Print("\narr2: ")
 conclusion(arr2)

 // Задание 4
 str := make([]byte, n)
 for i := 0; i < n; i++ {
     //рандом символов
     //тип данных byte — это алиас к типу uint8 (0-255)
  str[i] = byte(rand.Intn('z'-'A'+1) + 'A')
 }
 fmt.Print("\nstr: ")
 fmt.Println(string(str))
 fmt.Print("Replacement: ")
 replacement(str)
 fmt.Print("\nstr: ")
 fmt.Println(string(str))

 // Задание 5
 arr3 := make([]int, n)
 for i := 0; i < n; i++ {
  arr3[i] = rand.Intn(1001) + 1000
 }
 fmt.Print("\narr3: ")
 conclusion(arr3)
 //Сортировка
 sort.Sort(sort.Reverse(sort.IntSlice(arr3)))
 fmt.Print("\nSorted array: ")
 fmt.Print("\narr3: ")
 conclusion(arr3)
 newArr := repeat(arr3)
 fmt.Print("\nWith repeating digits: ")
 fmt.Print("\nnewArr: ")
 conclusion(newArr)
}
