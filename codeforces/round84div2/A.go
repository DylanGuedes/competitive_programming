package main
import "fmt"

func main() {
  var bestnumberever string
  for {
    fmt.Scanf("%s", &bestnumberever)
    fmt.Println("BESTNUMBERVER -> ", bestnumberever)
    if len(bestnumberever)==0 {
      break;
    }

    var total int
    for _, it := range bestnumberever {
      if total > 7 {
        break
      }
      if it == '4' || it == '7' {
        total++
      }
    }

    if total == 4 || total == 7 {
      fmt.Println("YES")
    } else {
      fmt.Println("NO")
    }
  }
}
