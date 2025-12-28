function roll(min, max, floatFlag = false) {
    let r = Math.random() * (max - min) + min
    return floatFlag ? r : Math.floor(r)
}

// console.log(roll(1, 5 ))

let userNames = ['James', 'Jane', 'Ryan', 'Rebecca']
// Ages between 12 and 64
// Heights between 5.1 and 6 meters

let user = {
    name: userNames[roll(0, userNames.length)],
    age: roll(12, 65),
    height: roll(5.1, 6.1, 1).toFixed(1)
}
console.log(user)

let possibleProducts = ["🍇", "🍈", "🍉", "🍊", "🍋", "🍌", "🍍", "🥭", "🍎", "🍏", "🍐", "🍑", "🍒", "🍓", "🥝", "🍅", "🥥", "🥑", "🍆", "🥔", "🥕", "🌽", "🌶", "🥒", "🥬", "🥦"]

let products = [...Array(5)].map((_, i) => {
    return {
        index: i,
        title: possibleProducts[roll(0, possibleProducts.length)],
        price: roll(2, 10, 1).toFixed(2),
        count: roll(1, 6)
    }
})
console.log(products)