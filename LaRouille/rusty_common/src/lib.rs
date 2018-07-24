
#[no_mangle]
pub extern fn add(lhs: u32, rhs: u32) -> u32 {
    lhs + rhs
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
