function createDP(albums, photos) {
	/* dp table */
	var table = []
	/* initialize dp table */
	albums.forEach(album => {
		table[album] = [album]
	})

	/* loop each number of photos */
	for(var i = 0; i < photos; i++) {
		/* loop each albums size */
		albums.forEach(album => {
			if(!!!table[i]) return

			/* initial array in table */
			table[i + album] = table[i + album] || table[i].concat(album)

			if(table[i].length + 1 < table[i + album].length) {
				/* in case of use current less than the other */
				table[i + album] = table[i].concat(album)
			}
		})
	}
	
	return table
}

function findAlbums(albums, photos, limit=2) {
	/* create table */
	var table = createDP(albums, photos)
	// table.forEach((val, i) => console.log(i, val))

	/* find posible solution */
	for(var i = 0; photos - i > 0 && photos + i < table.length; i++) {
		var insert, leftover
		if(i <= limit) {
			/* insert plastic not reach the limit */
			insert = table[photos - i] || []
		} else {
			insert = []
		}
		leftover = table[photos + i] || []

		// console.log(i, insert, leftover)
		if(leftover.length <= insert.length && leftover.length > 0) {
			return leftover
		} else if(leftover.length > 0){
			return leftover
		} else if(insert.length > 0) {
			return insert
		}
	}
}

var ans = findAlbums([24, 12, 16], 169)
console.log(ans.reduce((sum, val) => sum + val), ans)