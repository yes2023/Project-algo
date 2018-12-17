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

function findAlbums(albums, photos, limit=2) {
	let ans = []
	let insert, leftover

	ans = dfs(albums, photos)
	for(let i = 1; ans.length == 0; i++) {
		if(i <= limit) {
			insert = dfs(albums, photos - i)
		} else {
			insert = []
		}
		leftover = dfs(albums, photos + i)

		if(leftover.length <= insert.length && leftover.length > 0) {
			return leftover
		} else if(leftover.length > 0){
			return leftover
		} else if(insert.length > 0) {
			return insert
		}
	}
	return ans
}

var ans = findAlbums([24, 52, 28], 207)
console.log(ans.reduce((sum, val) => sum + val, 0), ans)
