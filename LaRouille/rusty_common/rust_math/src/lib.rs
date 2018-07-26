
extern crate libm;

use libm::F32Ext; // adds methods to `f32`

#[no_mangle]
pub extern fn add(lhs: u32, rhs: u32) -> u32 {
    lhs + rhs
}

#[no_mangle]
pub extern fn calc_nearest_integer_of_square_root(x: f32) -> i32 {
    let y = x.sqrt();
    let z = libm::truncf(y);
    z as i32
}

#[cfg(test)]
mod tests {

    use add;

    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
        assert_eq!(add(2, 2), 4);
    }
}
