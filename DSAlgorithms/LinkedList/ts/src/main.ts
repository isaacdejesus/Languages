import { linked_list } from "./linked_list";

const list = new linked_list();

list.add_to_head(11);
list.add_to_head(8);
list.add_to_end(3);
list.display_recursive(list.get_head());
let values_of_list = list.list_values(list.get_head());
console.log(values_of_list);
let values_of_list_recursive = (list.list_values_recursive(list.get_head()));
console.log(values_of_list_recursive);
let sum_of_list = list.sum_contents_of_list(list.get_head());
console.log(sum_of_list);
let sum_of_list_recursive = list.sum_contents_of_list_recursive(list.get_head());
console.log(sum_of_list_recursive);
console.log(list.is_item_in_list(list.get_head(), 9));
console.log(list.is_item_in_list(list.get_head(), 3));
console.log(list.is_item_in_list_recursive(list.get_head(), 9));
console.log(list.is_item_in_list_recursive(list.get_head(), 3));