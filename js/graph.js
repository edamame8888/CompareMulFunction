//make graph

Highcharts.chart('container', {

    title: {
        text: '整数の乗算に関しての実行時間の比較'
    },

    subtitle: {
        text: 'カラツバ法4,カラツバ法32,学校法'
    },
    xAxis:{
        title:{
            text: 'n'
        },
        categories: ['2^2','2^4', '2^8', '2^10', '2^12', '2^14', '2^16', '2^18']
    },
    yAxis: {
        type: 'logarithmic',
        title: {
            text: '時間[秒]'
        }
    },
    legend: {
        layout: 'vertical',
        align: 'right',
        verticalAlign: 'middle'
    },

    series: [{
        name: 'カラツバ法4',
        data: karatsuba4Time
    }, {
        name: 'カラツバ法32',
        data: karatsuba32Time
    }, {
        name: '学校法',
        data: schoolTime
    }],

    responsive: {
        rules: [{
            condition: {
                maxWidth: 500
            },
            chartOptions: {
                legend: {
                    layout: 'horizontal',
                    align: 'center',
                    verticalAlign: 'bottom'
                }
            }
        }]
    }

});
