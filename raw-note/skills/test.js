for (var i = 0; i < 3; i++) {
  setTimeout(() => {
    console.log((new Date(Date.now())).toUTCString())
  }, 1000)
}