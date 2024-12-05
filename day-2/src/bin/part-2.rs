fn main() -> Result<(), std::io::Error> {
    let input = std::fs::read_to_string("input.txt")?;
    let count = input
        .lines()
        .map(|line| {
            let levels = line
                .split_whitespace()
                .map(|x| x.parse::<i32>().unwrap())
                .collect::<Vec<_>>();

            if levels.len() < 2 {
                return true;
            }

            let is_safe = |levels: &[i32]| {
                if levels.len() < 2 {
                    return true;
                }

                let increasing = (levels[1] - levels[0]) >= 0;
                for pair in levels.windows(2) {
                    let diff: i32 = pair[1] - pair[0];
                    if (diff >= 0) != increasing {
                        return false;
                    }

                    if !(1..=3).contains(&diff.abs()) {
                        return false;
                    }
                }

                true
            };

            for i in 0..=levels.len() {
                if i == 0 {
                    if is_safe(&levels) {
                        return true;
                    }

                    continue;
                }

                let mut new_levels = levels.clone();
                new_levels.remove(i - 1);
                if is_safe(&new_levels) {
                    return true;
                }
            }

            false
        })
        .fold(0i32, |count, safe| count + if safe { 1 } else { 0 });

    println!("{}", count);
    Ok(())
}
