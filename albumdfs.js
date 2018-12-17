const sumAlbum = (albums) => albums.reduce((sum, val) => sum + val, 0)

function dfs(albums, photos) {
	let stack = [[]]
	let ans = []

	while(stack.length > 0) {
		let current = stack.pop()
		let amount = sumAlbum(current)

		if(amount == photos && (ans.length == 0 || current.length < ans.length)) {
			ans = current
		}

		albums.forEach(album => {
			if(amount + album <= photos) {
				stack.push(current.concat(album))
			}
		})
	} 
	return ans
}

var ans = dfs([24, 52, 28], 204)
console.log(ans.reduce((sum, val) => sum + val, 0), ans)
