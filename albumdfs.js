function dfs(albums, photos) {
	let stack = [[]]
	while(stack.length > 0) {
		let current = stack.pop()
		let amount = current.reduce((sum, val) => sum + val, 0)
		if(amount == photos) {
			return current
		}
		albums.forEach(album => {
			if(amount + album <= photos) {
				stack.push(current.concat(album))
			}
		})
	} 
	return []
}

var ans = dfs([10, 12, 20, 32], 168)
console.log(ans.reduce((sum, val) => sum + val, 0), ans)