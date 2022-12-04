open Printf

let file = "input.txt"

let parse_to_ints (s: string) =
    let values = String.split_on_char '-' s in
    List.map int_of_string values
;;

let get_record (s: string) =
    let values = String.split_on_char ',' s in
    List.iter print_endline values

let lines f = 
    let contents = In_channel.with_open_bin f In_channel.input_all in
    let string = String.split_on_char '\n' contents in
    List.map get_record string
;;

