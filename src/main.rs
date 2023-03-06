fn main() {
    const BIG_NUM:usize = 10000;//10,000
    let mut nums = Vec::from_iter(2..BIG_NUM);
    
    
    let mut n = 0; //index of nums
    let mut add:bool = true;
    while n<nums.len() {
        
        for i in *nums.first().unwrap()..(BIG_NUM/2) {
            let a = nums[n]*i;
            // print!("{} ",a);
            // print!("{} ",a);
            // if nums.contains(&a) {
            //     nums.remove(nums.binary_search(&a).unwrap());
            //     add=false;
            // }
            //v2
            if let Some(index) = nums.binary_search(&a).ok() {
                nums.remove(index);
                add=false;
            }
        }
        if add{n+=1;} else {add=true}

    }


    println!("{:?}\nlength:{}",nums,nums.len());
}

//6.392
//1.264s with v2
//0.265 0.287 0.308 for 10,000

//20.275s for 100,000
//15.691s for 100,000 pt. 2

//47m for 1,000,000e